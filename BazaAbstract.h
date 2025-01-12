#ifndef BAZAABSTRACT_H
#define BAZAABSTRACT_H
#include <QString>
#include <QJsonObject>


class BazaAbstract
{
public :
    virtual QString DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek)=0;
    virtual void KasowanieRekordu(int _id)=0;
    virtual void DajRekordReset()=0;
    virtual QJsonObject DajRekord(int _indexId)=0;
    virtual QJsonObject DajRekord()=0;

    static BazaAbstract& Instancja();
    virtual void EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek)=0;
    virtual bool ZapisDoPliku(const QString &fileName)=0;
    virtual bool OdczytZPliku(const QString &fileName)=0;
    virtual bool ZnajdzPlik(QString plik)=0;
    virtual int Rozmiar()=0;

};

#endif // BAZAABSTRACT_H
