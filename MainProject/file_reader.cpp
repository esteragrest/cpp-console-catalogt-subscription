#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

stoimost convert(char* str)
{
    stoimost result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.cena = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    return result;
}

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
            file >> item->nuz.first_kateg;
            file >> tmp_buffer;
            item->pocup = convert(tmp_buffer);
            file >> tmp_buffer;
            item->sklad = convert(tmp_buffer);
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
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