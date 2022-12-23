#include "filter.h"
#include "product_catalog.h"
#include <cstring>
#include <fstream>
product_catalog** filter(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size)
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
//������ ����� ������. ��� �������� ������ ����������
bool check_prod_by_kat(product_catalog* element)
{
    return strcmp(element->kat, "����������") == 0;
}
//������� ����� ������. ��� �������� ������ ������� � ����� ���� 100�
bool check_prod_by_cena(product_catalog* element)
{
    return element->cena > 100;
}
void Selectionsort(product_catalog** subscriptions, int size)
{
    int max = 0;
    int tmp = 0;
    for (int i = 0;i < size - 1;i++)
    {
        max = i;
       for (int j = i + 1;j < size;j++)
       {
           if (subscriptions[j]->kol > subscriptions[max]->kol)
           {
               max = j;
           }
       }
       tmp = subscriptions[i]->kol;
       subscriptions[i]->kol = subscriptions[max]->kol;
       subscriptions[max]->kol = tmp;

    }
}

void merge(product_catalog** subscriptions, int size)
{
    int mid = size / 2; // ������� �������� ����������� ������������������
    if (size % 2 == 1)
        mid++;
    int h = 1; // ���
    // �������� ������ ��� ����������� ������������������
    product_catalog** c = new product_catalog * [size];
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;   // ������ ������� ����
        int j = mid; // ������ ������� ����
        int k = 0;   // ������ �������� � �������������� ������������������
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { // ���� �� ����� �� ����� ����
              // ��������� ��������� ������� ����������� ������������������
              // ������� �� ���� ���������������
                if (subscriptions[i]->kol >= subscriptions[j]->kol)
                {
                    c[k] = subscriptions[i];
                    i++; k++;
                }
                else {
                    c[k] = subscriptions[j];
                    j++; k++;
                }
            }
            while (i < step)
            { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = subscriptions[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = subscriptions[j];
                j++; k++;
            }
            
            step = step + h; // ��������� � ���������� �����
        }
        h = h * 2;
        // ��������� ������������� ������������������ (������������� �������) � �������� ������
        for (i = 0; i < size; i++)
            subscriptions[i] = c[i];
    }
}
void Selectionsort_str(product_catalog** subscriptions, int size)
{
    product_catalog** c = new product_catalog * [size];
    int min = 0;
    
    for (int i = 0;i < size - 1;i++)
    {
        min = i;
        for (int j = i + 1;j < size;j++)
        {
            if (strlen(subscriptions[j]->kat) < strlen(subscriptions[min]->kat))
            {
                min = j;
            }
        }
        
        std::swap(subscriptions[i]->kat, subscriptions[min]->kat);
        

    }
}

void merge_str(product_catalog** subscriptions, int size)
{
    int mid = size / 2; // ������� �������� ����������� ������������������
    if (size % 2 == 1)
        mid++;
    int h = 1; // ���
    // �������� ������ ��� ����������� ������������������
    product_catalog** c = new product_catalog * [size];
    int step;
    while (h < size)
    {
        step = h;
        int i = 0;   // ������ ������� ����
        int j = mid; // ������ ������� ���� 
        int k = 0;   // ������ �������� � �������������� ������������������
        while (step <= mid)
        {
            while ((i < step) && (j < size) && (j < (mid + step)))
            { // ���� �� ����� �� ����� ����
              // ��������� ��������� ������� ����������� ������������������
              // ������� �� ���� ���������������
                if (strlen(subscriptions[i]->kat) < strlen(subscriptions[j]->kat))
                {
                    c[k] = subscriptions[i];
                    i++; k++;
                }
                else {
                    c[k] = subscriptions[j];
                    j++; k++;
                }
            }
            while (i < step)
            { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = subscriptions[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < size))
            {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
                c[k] = subscriptions[j];
                j++; k++;
            }
            step = step + h; // ��������� � ���������� �����
        }
        h = h * 2;
        // ��������� ������������� ������������������ (������������� �������) � �������� ������
        for (i = 0; i < size; i++)
            subscriptions[i] = c[i];
    }
}
void cena_sort(product_catalog** report, int size)
{
    int i = 0;
    int buf;
    while (i < size)
    {
        int count = 0;
        char* kat = report[i]->kat;
        for (int j = 0; j < size; j++)
        {
            if (strcmp(report[j]->kat, kat) == 0)
                count++;
        }
        if (count == 1)
            i++;
        else
        {
            buf = i;
            product_catalog** c = new product_catalog * [count];
            for (int j = 0; j < count; j++)
            {
                c[j] = report[buf];
                buf++;

            }
            int min;
            for (int k = 0; k < count; k++)
            {
                min = k;
                for (int j = k + 1; j < count; j++)
                    if (c[j]->cena > c[min]->cena)
                        min = j;
                std::swap(c[k], c[min]);
            }
            for (int l = 0; l < count; l++)
            {
                report[i] = c[l];
                i++;
            }
        }
    }
}