#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
class BazaDanych
{
private:

public:
    BazaDanych();

    int id;
    QJsonArray db;
    QString plik_db;
    int indexNext;

    QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek);
    void KasowanieRekordu(int _id);
    void DajRekordReset();
    QJsonObject DajRekord(int _indexId);
    QJsonObject DajRekord();

    static BazaDanych& Instancja();
    void EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek);
    bool ZapisDoPliku(const QString &fileName);
    bool OdczytZPliku(const QString &fileName);
    bool ZnajdzPlik(QString plik);
};
#endif // BAZADANYCH_H
