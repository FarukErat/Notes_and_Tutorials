#include "car.h"

constexpr auto RECORD_NUM = 406;

int main()
{
     Car *car;
     std::ifstream resTextFile("res_car_records.txt", std::ios::in);
     std::ofstream tarTextFile("tar_car_records.txt", std::ios::out | std::ios::trunc);
     std::fstream binFile("bin_car_records.bin", std::ios::out | std::ios::in | std::ios::trunc | std::ios::binary);
     std::string line;
     getline(resTextFile, line);
     getline(resTextFile, line);
     for (int i = 0; i < RECORD_NUM; i++)
     {
          car = new Car();
          resTextFile >> *car;
          tarTextFile << *car;
          std::cout << *car;
          binFile << *car;
     }
     resTextFile.close();
     tarTextFile.close();
     Car a1, a2, a3;
     a1.getRecord(binFile, 11);
     a2.getRecord(binFile, 228);
     a3.getRecord(binFile, 401);
     std::cout << "######" << std::endl;
     std::cout << "Size of a car: " << a1.size() << " bytes." << std::endl;
     std::cout << "######" << std::endl;
     std::cout << "11. record:" << std::endl
          << a1;
     std::cout << "228. record:" << std::endl
          << a2;
     std::cout << "401. record:" << std::endl
          << a3;
     binFile.close();
}