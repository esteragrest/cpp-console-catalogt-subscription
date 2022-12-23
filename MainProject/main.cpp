#include <iostream>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(product_catalog* subscriptions)
{
    
    cout << "��������� ������ ������........: ";
    //����� ��������� ������ ������
    cout << subscriptions->cena << endl;
    cout << "���-�� ������� �� ������........: ";
    //����� ���-�� ������� �� ������
    cout << subscriptions->kol << endl;
    cout << "���������........: ";
    //����� ��������� ������
    cout << subscriptions->kat << endl;
    cout << "�������� ������........: ";
    //����� �������� ������
    cout << subscriptions->nazvanie << endl;
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �9. GIT\n";
    cout << "������� �10. ������� �������\n";
    cout << "�����: ����������� �����\n";
    cout << "12 ������\n\n";
    product_catalog* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** ������� ������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(subscriptions[i]);
        }
        bool (*check_function)(product_catalog*) = NULL;
        cout << "\n�������� ������ ���������� ��� ��������� ������:\n";
        cout << "1) ������� ��� ������ � ��������� ������������.\n";
        cout << "2) ������� ��� ������ ���������� ���� 100 ������.\n";
        cout << "\n������� ����� ���������� ������: ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_prod_by_kat; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** ������ � ��������� ������������ *****\n\n";
            break;
        case 2:
            check_function = check_prod_by_cena; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** ��� ������ ���������� ���� 100 ������ *****\n\n";
            break;
        default:
            throw "������������ ����� ������";
        }
        if (check_function)
        {
            int new_size;
            product_catalog** filtered = filter(subscriptions, size, check_function, new_size);
            cout << "�������� ��������:\n";
            cout << "1)���������� ������� (Selection sort) �� �������� ���������� ������� �� ������.\n";
            cout << "2)���������� ��������� (Merge sort) �� �������� ���������� ������� �� ������. \n";
            cout << "3)���������� ������� (Selection sort) �� ����������� ��������� ������, � � ������ ����� ��������� �� �������� ���������.\n";
            cout << "4)���������� ��������� (Merge sort) �� ����������� ��������� ������, � � ������ ����� ��������� �� �������� ���������\n";
            cout << "\n������� ����� ���������� ������: ";
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
                throw "������������ ����� ������";
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


