#include <iostream>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №0. Библиотечный абонемент\n";
    cout << "Автор: Сергей Ермоченко\n\n";
    product_catalog* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->reader.last_kateg << '\n';
            cout << subscriptions[i]->reader.first_kateg << '\n';
            cout << subscriptions[i]->reader.middle_kateg << '\n';
            cout << subscriptions[i]->finish.cena << '\n ';
            cout << subscriptions[i]->start.cena << '\n ';
            cout << subscriptions[i]->author.last_kateg << '\n';
            cout << subscriptions[i]->author.first_kateg << '\n';
            cout << subscriptions[i]->author.middle_kateg << '\n';
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