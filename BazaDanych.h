#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include <QJsonObject>
#include <QJsonArray>
class BazaDanych
{
public:
    BazaDanych();

    int id;
    QJsonArray db;

    QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek);
    void KasowanieRekordu(int _id);
    QJsonObject DajRekord(int _index);
};
#endif // BAZADANYCH_H
