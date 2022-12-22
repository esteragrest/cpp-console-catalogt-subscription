#include <iostream>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"

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
            cout << "��������� ������ ������........: ";
            //����� ��������� ������ ������
            cout << subscriptions[i]->cena << endl;
            cout << "���-�� ������� �� ������........: ";
            //����� ���-�� ������� �� ������
            cout << subscriptions[i]->kol << endl;
            cout << "���������........: ";
            //����� ��������� ������
            cout << subscriptions[i]->kat << endl;
            cout << "�������� ������........: ";
            //����� �������� ������
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


