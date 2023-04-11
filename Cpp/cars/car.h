#pragma once

#include <iostream> // ostream, stoi, stof, ios, endl
#include <fstream>  // ifstream, fstream
#include <string>   // getline, c_str
#include <cstring>  // strcpy

using std::ostream;
using std::endl;
using std::ifstream;
using std::string;
using std::stof;
using std::stoi;
using std::fstream;

class Car
{

private:
    char name[100];
    char origin[100];
    int cylinders;
    int model;
    float mpg;
    float displacement;
    float horsepower;
    float weight;
    float acceleration;

public:
    Car()
    {
        strcpy(name, "");
        mpg = 0.0;
        cylinders = 0;
        displacement = 0.0;
        horsepower = 0.0;
        weight = 0.0;
        acceleration = 0.0;
        model = 0;
        strcpy(origin, "");
    }

    friend ostream &operator<<(ostream &o, Car &a)
    {
        o << "#" << a.name << "||" << a.mpg << "||" << a.cylinders << "||" << a.displacement << "||" << a.horsepower << "||" << a.weight << "||" << a.acceleration << "||" << a.model << "||" << a.origin << endl;
        o.flush();
        return o;
    }

    friend ifstream &operator>>(ifstream &file, Car &a)
    {
        string data;
        getline(file, data, '\t');
        strcpy(a.name, data.c_str());
        getline(file, data, '\t');
        a.mpg = stof(data.c_str());
        getline(file, data, '\t');
        a.cylinders = stoi(data.c_str());
        getline(file, data, '\t');
        a.displacement = stof(data.c_str());
        getline(file, data, '\t');
        a.horsepower = stof(data.c_str());
        getline(file, data, '\t');
        a.weight = stof(data.c_str());
        getline(file, data, '\t');
        a.acceleration = stof(data.c_str());
        getline(file, data, '\t');
        a.model = stoi(data.c_str());
        getline(file, data, '\n');
        strcpy(a.origin, data.c_str());
        return file;
    }

    friend fstream &operator>>(fstream &file, Car &a)
    {
        file.read(a.name, sizeof(a.name));
        file.read(reinterpret_cast<char *>(&a.mpg), sizeof(float));
        file.read(reinterpret_cast<char *>(&a.cylinders), sizeof(int));
        file.read(reinterpret_cast<char *>(&a.displacement), sizeof(float));
        file.read(reinterpret_cast<char *>(&a.horsepower), sizeof(float));
        file.read(reinterpret_cast<char *>(&a.weight), sizeof(float));
        file.read(reinterpret_cast<char *>(&a.acceleration), sizeof(float));
        file.read(reinterpret_cast<char *>(&a.model), sizeof(int));
        file.read(a.origin, sizeof(a.origin));
        return file;
    }

    friend fstream &operator<<(fstream &file, Car &a)
    {
        file.write(a.name, sizeof(a.name));
        file.write(reinterpret_cast<char *>(&a.mpg), sizeof(float));
        file.write(reinterpret_cast<char *>(&a.cylinders), sizeof(int));
        file.write(reinterpret_cast<char *>(&a.displacement), sizeof(float));
        file.write(reinterpret_cast<char *>(&a.horsepower), sizeof(float));
        file.write(reinterpret_cast<char *>(&a.weight), sizeof(float));
        file.write(reinterpret_cast<char *>(&a.acceleration), sizeof(float));
        file.write(reinterpret_cast<char *>(&a.model), sizeof(int));
        file.write(a.origin, sizeof(a.origin));
        file.flush();
        return file;
    }

    void getRecord(fstream &file, int order)
    {
        file.seekg((order - 1) * size(), std::ios::beg);
        file >> *this;
    }

    int size()
    {
        return 2 * sizeof(int) + 5 * sizeof(float) + sizeof(name) + sizeof(origin);
    }
};