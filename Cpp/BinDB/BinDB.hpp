#pragma once
#ifndef BIN_DB
#define BIN_DB

#include <iostream>

template <typename T>
class BinDB
{
private:
    char *fileName;
    unsigned int numOfElements;

public:
    /**
     * @brief Construct a new object
     *
     * @param fileName name of the file
     * @param numOfElements number of elements in the file
     */
    BinDB(const char *fileName, unsigned int numOfElements);

    /**
     * @brief Write data to the file
     *
     * @param data pointer to the array of data
     * @param size number of elements to write
     * @param offset beginning of the array to write to
     * @return true
     * @return false
     */
    bool write(T *data, unsigned int size, unsigned int offset);

    /**
     * @brief Read data from the file
     *
     * @param data pointer to the array of data
     * @param size number of elements to read
     * @param offset beginning of the array to read from
     * @return true
     * @return false
     */
    bool read(T *data, unsigned int size, unsigned int offset);
};

template <typename T>
BinDB<T>::BinDB(const char *fileName, unsigned int numOfElements)
{
    // initialize the variables
    this->fileName = (char*)fileName;
    this->numOfElements = numOfElements;

    // check if the file exists
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        // create the file if it doesn't exist
        file = fopen(fileName, "wb");
        if (file == NULL)
        {
            printf("Error: Unable to create file %s\n", fileName);
            exit(1);
        }
        // if the file is newly created, initialize it
        else
        {
            T *data = new T[numOfElements];
            fwrite(data, sizeof(T), numOfElements, file);
            fclose(file);
        }
    }
    else
    {
        fclose(file);
    }
}

template <typename T>
bool BinDB<T>::write(T *data, unsigned int size, unsigned int offset)
{
    // check if the operation is to be performed in the range of the file
    if (offset + size > numOfElements)
    {
        printf("Error: Out of range\n");
        return false;
    }

    // open the file
    FILE *file = fopen(fileName, "rb+");
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", fileName);
        return false;
    }

    // go to the offset and write the data to the file
    fseek(file, offset * sizeof(T), SEEK_SET);
    fwrite(data, sizeof(T), size, file);
    fclose(file);

    return true;
}

template <typename T>
bool BinDB<T>::read(T *data, unsigned int size, unsigned int offset)
{
    // check if the operation is to be performed in the range of the file
    if (offset + size > numOfElements)
    {
        printf("Error: Out of range\n");
        return false;
    }

    // open the file
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Error: Unable to open file %s\n", fileName);
        return false;
    }

    // go to the offset and assign the data to the array
    fseek(file, offset * sizeof(T), SEEK_SET);
    fread(data, sizeof(T), size, file);
    fclose(file);

    return true;
}

#endif // BIN_DB
