#ifndef FILTER_H
#define FILTER_H

#include "product_catalog.h"

product_catalog** filter(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size);
bool check_prod_by_kat(product_catalog* element);
bool check_prod_by_cena(product_catalog* element);
void Selectionsort(product_catalog** subscriptions, int size);
void merge(product_catalog** subscriptions, int size);
void Selectionsort_str(product_catalog** subscriptions, int size);
void merge_str(product_catalog** subscriptions, int size);
void cena_sort(product_catalog** subscriptions, int size);







#endif

