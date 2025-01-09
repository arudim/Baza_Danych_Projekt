#include "BazaDanych.h"
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>
static BazaDanych instancja_bazy;

BazaDanych& BazaDanych::Instancja(){
    return instancja_bazy;
}

BazaDanych::BazaDanych() {
    id=0;
}

QString BazaDanych::DodawnieRekordu(int _rok, QString _tytul, QString _rezyser, QString _gatunek){
    QString ret="";
    QJsonObject rekord;

    rekord["id"]= id++;
    rekord["rok"] = _rok;
    rekord["tytul"] = _tytul;
    rekord["rezyser"] = _rezyser;
    rekord["rodzaj"] = _gatunek;
    db.append(rekord);
    return ret;
}

void BazaDanych::KasowanieRekordu(int _id){
    for(int i =0; i<db.size();i++){
        if(db[i].toObject()["id"]==_id){
            db.removeAt(i);
            break;

        }
    }
}

QJsonObject BazaDanych::DajRekord(int _index){
    QJsonObject ret;
    if(_index>=db.size()){
        ret.empty();
    }
    else{
        ret=db[_index].toObject();
    }
    return ret;
}

void BazaDanych::EdytowanieRekordu(int _id, int _rok, QString _tytul, QString _rezyser, QString _gatunek){
    QJsonObject rekord=DajRekord(_id);
    rekord["rok"] = _rok;
    rekord["tytul"] = _tytul;
    rekord["rezyser"] = _rezyser;
    rekord["rodzaj"] = _gatunek;
    db.replace(_id,rekord);
}

bool BazaDanych::ZapisDoPliku(const QString &fileName){
    QFile file(fileName);
    bool a=true;
    if(!file.open(QIODevice::WriteOnly)){
        a=false;
        return a;
    }
    QJsonDocument doc(db);
    file.write(doc.toJson());
    file.close();
    return a;
}

bool BazaDanych::OdczytZPliku(const QString &fileName){
    bool a=true;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        a=false;
        return a;
    }
    QByteArray data= file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    db=doc.array();
    file.close();
    return a;
}


