#include <iostream>
#include "processing.h"
#include <cstring>
#include <fstream>
    

product_catalog** schet(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size)
{
	product_catalog** result = new product_catalog * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}
bool check_prod_by_kat1(product_catalog* element)
{
	return strcmp(element->kat, "Промтовары") == 0;
}
bool check_prod_by_kat2(product_catalog* element)
{
	return strcmp(element->kat, "Искусство") == 0;
}
bool check_prod_by_kat3(product_catalog* element)
{
	return strcmp(element->kat, "Детям") == 0;
}
bool check_prod_by_kat4(product_catalog* element)
{
	return strcmp(element->kat, "Красота") == 0;
}
int process(product_catalog* subscriptions[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += subscriptions[i]->cena;
	}
	
	return sum;
}

