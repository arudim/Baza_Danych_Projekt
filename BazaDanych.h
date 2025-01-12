#ifndef BAZADANYCH_H
#define BAZADANYCH_H
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "BazaAbstract.h"
class BazaDanych : public BazaAbstract
{
private:

public:
    BazaDanych();
    virtual QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek);
    virtual void KasowanieRekordu(int _id);
    virtual void DajRekordReset();
    virtual QJsonObject DajRekord(int _indexId);
    virtual QJsonObject DajRekord();

    static BazaAbstract& Instancja();
    virtual void EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek);
    virtual bool ZapisDoPliku(const QString &fileName);
    virtual bool OdczytZPliku(const QString &fileName);
    virtual bool ZnajdzPlik(QString plik);
    virtual int Rozmiar();

    int id;
    QJsonArray db;
    QString plik_db;
    int indexNext;

};
#endif // BAZADANYCH_H
