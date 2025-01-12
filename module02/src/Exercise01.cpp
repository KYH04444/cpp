/********************************************************************
				2025.01.10
				Yonghee Kim 

				module02 Using OOP concepts, make your own car
*********************************************************************/
#include <iostream>
#include <cstring>
#include <memory>
#include "carPart.h"

int main(int argc, char* argv[]) {
	Car SDV;
	std::string Wheels[4] = {"Front Right", "Front Left", "Back right",  "Back Left"};
	std::string sensors[2] = {"LiDAR", "Camera"};
	SDV.getEngine()->setEngineName("BMW engine");
	SDV.getBrake()-> setBrakeName("Hyundai brake");


	for (int i = 0; i < 4; ++i) {
		SDV.getWheel()->setWheelNumber(Wheels[i], i);
	}

	for (int i = 0; i < 2; ++i) {
		SDV.getSensor()->setSensorsName(sensors[i], i);
	}
	
	SDV.printParts();
	return 0;
}