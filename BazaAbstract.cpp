#include "BazaAbstract.h"
BazaAbstract &dba=0;
BazaAbstract& BazaAbstract::Instancja()
{
    return *dba;
}
