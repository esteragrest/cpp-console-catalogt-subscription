#include <iostream>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №10. Каталог товаров\n";
    cout << "Автор: Провальская Дарья\n\n";
    product_catalog* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** Каталог товаров *****\n\n";
        for (int i = 0; i < size; i++)
        {

            cout << subscriptions[i]->nuz.first_kateg << '\n';

            cout << subscriptions[i]->pocup.cena << '\n ';
            cout << subscriptions[i]->sklad.kol << '\n ';

            cout << subscriptions[i]->nazvanie << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}