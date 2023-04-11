#include "car.h"

constexpr auto RECORD_NUM = 406;

using std::ofstream;
using std::ios;
using std::cout;

int main()
{
     Car *car;
     ifstream resTextFile("res_car_records.txt", ios::in);
     ofstream tarTextFile("tar_car_records.txt", ios::out | ios::trunc);
     fstream binFile("bin_car_records.bin", ios::out | ios::in | ios::trunc | ios::binary);
     string line;
     getline(resTextFile, line);
     getline(resTextFile, line);
     for (int i = 0; i < RECORD_NUM; i++)
     {
          car = new Car();
          resTextFile >> *car;
          tarTextFile << *car;
          cout << *car;
          binFile << *car;
     }
     resTextFile.close();
     tarTextFile.close();
     Car a1, a2, a3;
     a1.getRecord(binFile, 11);
     a2.getRecord(binFile, 228);
     a3.getRecord(binFile, 401);
     cout << "######" << endl;
     cout << "Size of a car: " << a1.size() << " bytes." << endl;
     cout << "######" << endl;
     cout << "11. record:" << endl
          << a1;
     cout << "228. record:" << endl
          << a2;
     cout << "401. record:" << endl
          << a3;
     binFile.close();
}