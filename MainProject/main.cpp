#include <iostream>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(product_catalog* subscriptions)
{
    
    cout << "Стоимость одного товара........: ";
    //вывод стоимость одного товара
    cout << subscriptions->cena << endl;
    cout << "Кол-во товаров на складе........: ";
    //вывод кол-ва товаров на складе
    cout << subscriptions->kol << endl;
    cout << "Категория........: ";
    //вывод категории товара
    cout << subscriptions->kat << endl;
    cout << "Название товара........: ";
    //вывод названия товара
    cout << subscriptions->nazvanie << endl;
    cout << '\n';
}

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
            output(subscriptions[i]);
        }
        bool (*check_function)(product_catalog*) = NULL;
        cout << "\nВыберите способ фильтрации или обработки данных:\n";
        cout << "1) Вывести все товары в категории «Промтовары».\n";
        cout << "2) Вывести все товары стоимостью выше 100 рублей.\n";
        cout << "\nВведите номер выбранного пункта: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_prod_by_kat; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Товары в категории «Промтовары» *****\n\n";
            break;
        case 2:
            check_function = check_prod_by_cena; // присваиваем в указатель на функцию соответствующую функцию
            cout << "***** Все товары стоимостью выше 100 рублей *****\n\n";
            break;
        default:
            throw "Некорректный номер пункта";
        }
        if (check_function)
        {
            int new_size;
            product_catalog** filtered = filter(subscriptions, size, check_function, new_size);
            cout << "Выберите критерии:\n";
            cout << "1)Сортировка выбором (Selection sort) по убыванию количества товаров на складе.\n";
            cout << "2)Сортировка слияниием (Merge sort) по убыванию количества товаров на складе. \n";
            cout << "3)Сортировка выбором (Selection sort) по возростанию категории товара, а в рамках одной категории по убыванию стоимости.\n";
            cout << "4)Сортировка слияниием (Merge sort) по возрастанию категории товара, а в рамках одной категории по убыванию стоимости\n";
            cout << "\nВведите номер выбранного пункта: ";
            int sort;
            cin >> sort;
            switch (sort)
            {
            case 1:
                Selectionsort(filtered, new_size);
                break;
            case 2:
                merge(filtered, new_size);
                break;
            case 3:
                Selectionsort_str(filtered, new_size);
                cena_sort(filtered, new_size);
                break;
            case 4:
                merge_str(filtered, new_size);
                cena_sort(filtered, new_size);
                break;
            default:
                throw "Некорректный номер пункта";
            }
            for (int i = 0; i < new_size; i++)
            {
                output(filtered[i]);
            }
            delete[] filtered;
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


