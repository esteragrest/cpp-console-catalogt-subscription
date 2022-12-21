#ifndef PRODUCT_CATALOG
#define PRODUCT_CATALOG

#include "constants.h"

struct stoimost
{
    double cena;
    int kol;

};

struct kategori
{
    char first_kateg[MAX_STRING_SIZE];
};

struct product_catalog
{
    kategori nuz;
    stoimost pocup;
    stoimost sklad;
    char nazvanie[MAX_STRING_SIZE];
};

#endif
