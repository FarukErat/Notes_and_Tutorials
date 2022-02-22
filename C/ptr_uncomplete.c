#pragma once

#include "table.hpp"

char* Table::tempBoard(char origin[SIZE][SIZE])
{
    char* temp = new char[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        temp[i] = origin[i / SIZE][i % SIZE];
    }
    return temp;
}