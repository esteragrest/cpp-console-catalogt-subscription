#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>



void read(const char* file_name, product_catalog* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            product_catalog* item = new product_catalog;
            
            file >> item->cena;
            
            file >> item->kol;
            
            file >> item->kat;
            
            file.read(tmp_buffer, 2); // ������ ������� ������� �������
            file.getline(item->nazvanie, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "������ �������� �����";
    }
}