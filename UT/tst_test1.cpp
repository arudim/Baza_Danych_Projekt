#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "BazaJson.h"
#include "plik.h"
extern Plik *pa;

class Plik_Mock : public Plik {
 public:
  MOCK_METHOD(bool, open, (const QString &name, QIODeviceBase::OpenMode mode));
  MOCK_METHOD(void, close, ());
  MOCK_METHOD(qint64, write, (const QByteArray &data));
  MOCK_METHOD(QByteArray, readAll, ());
};
using namespace testing;

TEST(DBTEST, test1) {
  EXPECT_EQ(1, 1);
  ASSERT_THAT(0, Eq(0));
}

TEST(DBTEST, otwieranie_nieistnejacego_pliku_do_odczytu) {
  Plik_Mock m;
  BazaJson db_test;
  pa = &m;
  EXPECT_CALL(m, open(_, _)).WillOnce(Return(false));

  // Właściwy test
  db_test.OdczytZPliku("");
}

TEST(DBTEST, otwieranie_pustego_pliku_do_odczytu) {
  Plik_Mock m;
  BazaJson db_test;
  QByteArray pusty_odczyt;
  const QString s = "pusty.json";
  pa = &m;
  EXPECT_CALL(m, open(s, _)).WillOnce(Return(true));
  EXPECT_CALL(m, readAll()).WillOnce(Return(pusty_odczyt));
  EXPECT_CALL(m, close()).Times(1);

  // Właściwy test
  db_test.OdczytZPliku(s);
  EXPECT_THAT(db_test.Rozmiar(), 0);
}

TEST(DBTEST, otwieranie_pliku_do_odczytu_z_jednym_rekordem) {
  Plik_Mock m;
  BazaJson db_test;
  const QString s = "jeden_rekord.json";
  const QByteArray pojedynczy_rekord("{\"id\": 2,\"rezyser\": \"James Cameron\",\"rodzaj\": \"Science Fiction\",\"rok\": 2009,\"tytul\": \"Avatar\"}");
  pa = &m;
  EXPECT_CALL(m, open(s, _)).WillOnce(Return(true));
  EXPECT_CALL(m, readAll()).WillOnce(Return(pojedynczy_rekord));
  EXPECT_CALL(m, close()).Times(1);

  // Właściwy test
  db_test.OdczytZPliku(s);
  EXPECT_THAT(db_test.Rozmiar(), 0);
}

TEST(DBTEST, otwieranie_pliku_do_odczytu_z_jednym_elementem_tablicy) {
  Plik_Mock m;
  BazaJson db_test;
  const QString s = "jeden_rekord.json";
  const QByteArray pojedynczy_rekord("[{\"id\": 2,\"rezyser\": \"James Cameron\",\"rodzaj\": \"Science Fiction\",\"rok\": 2009,\"tytul\": \"Avatar\"}]");
  pa = &m;
  EXPECT_CALL(m, open(s, _)).WillOnce(Return(true));
  EXPECT_CALL(m, readAll()).WillOnce(Return(pojedynczy_rekord));
  EXPECT_CALL(m, close()).Times(1);

  // Właściwy test
  db_test.OdczytZPliku(s);
  EXPECT_THAT(db_test.Rozmiar(), 1);
}

TEST(DBTEST, otwieranie_pliku_do_odczytu_nie_json) {
  Plik_Mock m;
  BazaJson db_test;
  const QByteArray pojedynczy_rekord("to nie jest plik JSON");
  pa = &m;
  EXPECT_CALL(m, open(_, _)).WillOnce(Return(true));
  EXPECT_CALL(m, readAll()).WillOnce(Return(pojedynczy_rekord));
  EXPECT_CALL(m, close()).Times(1);

  // Właściwy test
  EXPECT_THAT(db_test.OdczytZPliku("jeden_rekord.json"), false);
  EXPECT_THAT(db_test.Rozmiar(), 0);
}

TEST(DBTEST, nieudane_otwarcie_pliku_do_zapisu) {
  Plik_Mock m;
  BazaJson db_test;
  const QString s = "plik.json";
  pa = &m;
  EXPECT_CALL(m, open(s, _)).WillOnce(Return(false));
  EXPECT_CALL(m, write(_)).Times(0);
  EXPECT_CALL(m, close()).Times(0);

  // Właściwy test
  EXPECT_THAT(db_test.ZapisDoPliku(s), false);
}

TEST(DBTEST, udany_zapis_do_pliku) {
  Plik_Mock m;
  BazaJson db_test;
  const QString s = "plik.json";
  const QByteArray definicja_bazy("[{\"id\": 2,\"rezyser\": \"James Cameron\",\"rodzaj\": \"Science Fiction\",\"rok\": 2009,\"tytul\": \"Avatar\"}]");
  QByteArray tresc_do_zapisu;
  pa = &m;
  db_test.db = QJsonDocument::fromJson(definicja_bazy).array();
  tresc_do_zapisu = QJsonDocument(db_test.db).toJson();
  EXPECT_CALL(m, open(s, _)).WillOnce(Return(true));
  EXPECT_CALL(m, write(tresc_do_zapisu)).WillOnce(Return(tresc_do_zapisu.size()));
  EXPECT_CALL(m, close()).Times(1);

  // Właściwy test
  EXPECT_THAT(db_test.ZapisDoPliku(s), true);
}

TEST(DBTEST, nieudany_zapis_do_pliku) {
  Plik_Mock m;
  BazaJson db_test;
  const QString s = "plik.json";
  const QByteArray definicja_bazy("[{\"id\": 2,\"rezyser\": \"James Cameron\",\"rodzaj\": \"Science Fiction\",\"rok\": 2009,\"tytul\": \"Avatar\"}]");
  QByteArray tresc_do_zapisu;
  pa = &m;
  db_test.db = QJsonDocument::fromJson(definicja_bazy).array();
  tresc_do_zapisu = QJsonDocument(db_test.db).toJson();
  EXPECT_CALL(m, open(s, _)).WillOnce(Return(true));
  EXPECT_CALL(m, write(tresc_do_zapisu)).WillOnce(Return(tresc_do_zapisu.size() - 1));
  EXPECT_CALL(m, close()).Times(1);

  // Właściwy test
  EXPECT_THAT(db_test.ZapisDoPliku(s), false);
}
