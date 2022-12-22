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
    cout << "Автор: Провальская Дарья\n";
    cout << "12 группа\n\n";
    product_catalog* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** Каталог товаров *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Стоимость одного товара........: ";
            //вывод стоимость одного товара
            cout << subscriptions[i]->cena << endl;
            cout << "Кол-во товаров на складе........: ";
            //вывод кол-ва товаров на складе
            cout << subscriptions[i]->kol << endl;
            cout << "Категория........: ";
            //вывод категории товара
            cout << subscriptions[i]->kat << endl;
            cout << "Название товара........: ";
            //вывод названия товара
            cout << subscriptions[i]->nazvanie << endl;
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

    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #10. Product catalog\n";
    cout << "Author: Provalskaya Darya\n";
    cout << "Group: 12\n";
    
    return 0;

}


