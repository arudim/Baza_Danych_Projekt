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

    QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek);
    void KasowanieRekordu(int _id);
    QJsonObject DajRekord(int _index);
    static BazaDanych& Instancja();
    void EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek);
};
#endif // BAZADANYCH_H
