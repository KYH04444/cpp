/********************************************************************
				2025.01.08
				Yonghee Kim 

				module01 Using OCF, Make software defined car model
*********************************************************************/

#include <iostream>
#include <cstring>
#include "softwareDefinedCar.h"

int main(int argc, char* argv[]) {
    int AutoDriveLevel[3] = {2, 3, 4};
    int EelectricLecel[3] = {50, 70, 100};
    bool Connectivity[3] = {false, true, true};
    bool OTA[3] = {true, false, true};

    std::string Lidar = "Ouster 128ch";
    std::string Camera = "Realsense D435i";

    softwareDefinedCar SDC("HYUNDAI", "Genesis", 2019);
    softwareDefinedCarLidar SDCL("BMW", "7-series", 2023, Lidar);
    softwareDefinedCarCamera SDCC("TESLA", "Model Y", 2022, Camera);

    SDC.setAutonomousDrivingLevel(AutoDriveLevel[0]);
    SDCL.setAutonomousDrivingLevel(AutoDriveLevel[1]);
    SDCC.setAutonomousDrivingLevel(AutoDriveLevel[2]);

    SDC.setElecrification(EelectricLecel[0]);
    SDCL.setElecrification(EelectricLecel[1]);
    SDCC.setElecrification(EelectricLecel[2]);

    SDC.setConnectivitiy(Connectivity[0]);
    SDCL.setConnectivitiy(Connectivity[1]);
    SDCC.setConnectivitiy(Connectivity[2]);

    SDC.setOverTheAir(OTA[0]);
    SDCL.setOverTheAir(OTA[1]);
    SDCC.setOverTheAir(OTA[2]);

    SDC.drive();
    SDC.printOtaInfo();

    SDCL.drive();
    SDCL.printOtaInfo();

    SDCC.drive();
    SDCC.printOtaInfo();    

    return 0;    
}