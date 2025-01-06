#include "film.h"



std::vector<Film1> f;



void addFilm(int year, const std::string &name, const std::string &director, const std::string &type) {
    Film1 a;
    a.year = year;
    a.name = name;
    a.director = director;
    a.type = type;
    f.push_back(a);

}

void deleteFilm(int index) {
    if (index >= 0 && index < f.size()) {
        f.erase(f.begin() + index);

    }
}

void kupe(){

}


