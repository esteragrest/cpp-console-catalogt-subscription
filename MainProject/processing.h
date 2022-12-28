#ifndef PROCESSING_H
#define PROCESSING_H

#include "product_catalog.h"

product_catalog** schet(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size);
int process(product_catalog* array[], int size);
bool check_prod_by_kat1(product_catalog* element);
bool check_prod_by_kat2(product_catalog* element);
bool check_prod_by_kat3(product_catalog* element);
bool check_prod_by_kat4(product_catalog* element);


#endif


