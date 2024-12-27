#ifndef FILM_H
#define FILM_H
#include <string>
#include <list>

using std::string;
using std::list;

class Rezyser{
    string imie;
    string nazwisko;
};

class Obsada{
    string imie;
    string nazwiako;
    string postac;
};


class Film
{
public:
    Film();
    string tytul;
    list<Rezyser> rezyserzy;
    int rok_produkcji;
    list<Obsada> aktorzy;
    list<string> producenci;
    string opis;

};

/*
Baza filmów:
tytuł: string
- reżyser: lista
    imie: string
    nazwisko: string
rok profukcji: int
-obsada: lista
   imie: string
   nazwisko: string
   postać: string
-producent: lista
    nazwa: string
plakat: bin
opis: string
 */
#endif // FILM_H
