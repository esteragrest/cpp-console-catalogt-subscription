#ifndef PRODUCT_CATALOG
#define PRODUCT_CATALOG

#include "constants.h"

struct stoimost
{
    int cena;

};

struct kategori
{
    char first_kateg[MAX_STRING_SIZE];
    char middle_kateg[MAX_STRING_SIZE];
    char last_kateg[MAX_STRING_SIZE];
};

struct product_catalog
{
    stoimost reader;
    kategori start;
    kategori finish;
    stoimost author;
    char nazvanie[MAX_STRING_SIZE];
};

#endif
