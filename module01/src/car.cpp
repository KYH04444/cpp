/*********************************************************
				2025.01.08
				Yonghee Kim 

				module01 what is the OCF
**********************************************************/

#include <iostream>
#include <cstring>
#include "car.h"

int main(int argc, char* argv[]) {
    car Car1("Hyundai", "Genesis", 2020);
    car Car2("BMW", "X6", 2015);
    car Car3("BENZ", "7 series", 2023);

    Car1.drive();
    Car2.drive();
    Car3.drive();

    Car1 = Car2; // 복사 대입 연산자
    Car1.drive();

    car Car4(Car3); // 복사 생성자
    Car4.drive();   
    sportsCar spCar1("WEGO", "Hunter", 2025, 400);
    spCar1.drive();
    return 0;

}

