#include "BazaDanych.h"
BazaDanych *dba = 0;
BazaDanych &
BazaDanych::Instancja() {
  return *dba;
}
