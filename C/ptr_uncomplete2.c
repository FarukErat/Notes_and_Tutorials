#pragma once

#include "table.hpp"

char** Table::tempBoard(char origin[SIZE][SIZE])
{
    char** temp = new char*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        temp[i] = new char[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            temp[i][j] = origin[i][j];
        }
    }
    return temp;
}