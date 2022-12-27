#include "processing.h"
#include <cstring>
#include <fstream>

//  ,      

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

int process(product_catalog* array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i]->cena;
	}
	return sum;
}

