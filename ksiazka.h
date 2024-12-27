#ifndef KSIAZKA_H
#define KSIAZKA_H
#include <string>
#include <list>

using std::string;
using std::list;

class autor{
public:
    string imie;
    string nazwisko;
};


class Ksiazka
{
public:
    Ksiazka();
    string tytul;
    list<autor> autorzy;
    int rok_wydania;
    string wydawnictwo;
    string ideks;
    string opis;
};

/*
Baza książek:
tytul: string
- autorzy: lista
    imie: string
    nazwisko: string
rok wydania: int
wydawnictwo: string
indeks_wydawniczy: string
okładka: bin
opis: string
 */
#endif // KSIAZKA_H
