#ifndef PRODUCT_CATALOG
#define PRODUCT_CATALOG

#include "constants.h"


struct product_catalog
{
    char kat[MAX_STRING_SIZE];
    int kol;
    double cena;
    char nazvanie[MAX_STRING_SIZE];
    int length;
};

#endif
