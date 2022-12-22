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
            //file >> tmp_buffer;
            file >> item->kol;
            //file >> tmp_buffer;
            file >> item->kat;
            //file >> tmp_buffer;
            file.read(tmp_buffer, 2); // чтения лишнего символа пробела
            file.getline(item->nazvanie, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}