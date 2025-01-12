#include "plik.h"

Plik *pa=0;
Plik& Plik::Instancja()
{
    return *pa;
}
