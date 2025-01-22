#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "plik.h"
#include "BazaJson.h"
extern Plik *pa;


class Plik_Mock : public Plik
{
public:
    MOCK_METHOD(bool, open,(const QString &name, QIODeviceBase::OpenMode mode));
    MOCK_METHOD(void, close,());
    MOCK_METHOD(qint64, write,(const QByteArray &data));
    MOCK_METHOD(QByteArray, readAll,());
};
using namespace testing;

TEST(DBTEST, test1)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(DBTEST, otwieranie_nieistnejacego_pliku){
    Plik_Mock m;
    BazaJson db_test;
    pa=&m;
    EXPECT_CALL(m,open(_,_)).WillOnce(Return(false));

    //Właściwy test
    db_test.OdczytZPliku("");
}

TEST(DBTEST, otwieranie_pustego_pliku){
    Plik_Mock m;
    BazaJson db_test;
    QByteArray pusty_odczyt;
    pa=&m;
    EXPECT_CALL(m,open(_,_)).WillOnce(Return(true));
    EXPECT_CALL(m,readAll()).WillOnce(Return(pusty_odczyt));
    EXPECT_CALL(m,close()).Times(1);

    //Właściwy test
    db_test.OdczytZPliku("pusty.json");
    EXPECT_THAT(db_test.Rozmiar(),0);
}

TEST(DBTEST, otwieranie_pliku_z_jednym_rekordem){
    Plik_Mock m;
    BazaJson db_test;
    QByteArray pojedynczy_rekord("{\"id\": 2,\"rezyser\": \"James Cameron\",\"rodzaj\": \"Science Fiction\",\"rok\": 2009,\"tytul\": \"Avatar\"}");
    pa=&m;
    EXPECT_CALL(m,open(_,_)).WillOnce(Return(true));
    EXPECT_CALL(m,readAll()).WillOnce(Return(pojedynczy_rekord));
    EXPECT_CALL(m,close()).Times(1);

    //Właściwy test
    db_test.OdczytZPliku("jeden_rekord.json");
    EXPECT_THAT(db_test.Rozmiar(),0);
}

TEST(DBTEST, otwieranie_pliku_z_jednym_elementem_tablicy){
    Plik_Mock m;
    BazaJson db_test;
    QByteArray pojedynczy_rekord("[{\"id\": 2,\"rezyser\": \"James Cameron\",\"rodzaj\": \"Science Fiction\",\"rok\": 2009,\"tytul\": \"Avatar\"}]");
    pa=&m;
    EXPECT_CALL(m,open(_,_)).WillOnce(Return(true));
    EXPECT_CALL(m,readAll()).WillOnce(Return(pojedynczy_rekord));
    EXPECT_CALL(m,close()).Times(1);

    //Właściwy test
    db_test.OdczytZPliku("jeden_rekord.json");
    EXPECT_THAT(db_test.Rozmiar(),1);
}

TEST(DBTEST, otwieranie_pliku_nie_json){
    Plik_Mock m;
    BazaJson db_test;
    QByteArray pojedynczy_rekord("to nie jest plik JSON");
    pa=&m;
    EXPECT_CALL(m,open(_,_)).WillOnce(Return(true));
    EXPECT_CALL(m,readAll()).WillOnce(Return(pojedynczy_rekord));
    EXPECT_CALL(m,close()).Times(1);

    //Właściwy test
    EXPECT_THAT(db_test.OdczytZPliku("jeden_rekord.json"),false);
    EXPECT_THAT(db_test.Rozmiar(),0);
}
