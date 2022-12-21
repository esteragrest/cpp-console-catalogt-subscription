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
            file >> item->reader.last_kateg;
            file >> item->reader.first_kateg;
            file >> item->reader.middle_kateg;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
            file >> item->author.last_kateg;
            file >> item->author.first_kateg;
            file >> item->author.middle_kateg;
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