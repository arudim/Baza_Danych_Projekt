#include "BazaDanych.h"
#include <QJsonObject>


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
