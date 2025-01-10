/********************************************************************
				2025.01.10
				Yonghee Kim 

				module02 Using OOP concepts, make your own car
*********************************************************************/
#include <iostream>
#include <cstring>
#include <memory>

class Part {
public:
    virtual void print() = 0;
	~Part() {}
};

class Engine : public Part {
private:
	std::string *EngineName;

public:
	void print() override {
		std::cout << "Engine name is" << *EngineName << ".\n";
	}

	void setEngineName(const std::string engineName) {
		*EngineName = engineName;
	}
};

class Brake : public Part {
private:
	std::string *BrakeName;

public:
	void print() override {
		std::cout << "Brake name is" << *BrakeName <<".\n";
	}

	void setBrakeName(const std::string brakeName) {
		*BrakeName = brakeName;
	}
};

class Wheel : public Part {
private:
	std::string *WheelName[4];

public:
	void print() override {
		std::cout << "This car has" << sizeof(WheelName) <<"wheels, and wheel Names are";
		for (int i = 0; i < 3; ++ i) {
			std::cout << *WheelName[i] <<",";
		}
			std::cout << *WheelName[3] << ".\n"; 
	}

	void setWheelNumber(const std::string &whellName, const int& idx) {
		*WheelName[idx] = whellName;		
	}
};

class Sensor : public Part {
private:
	std::string *Sensors[2];

public:
	void print() override {
		std::cout << "This car has" <<  sizeof(Sensors) << "Sensors, and Sensors are" << Sensors[0] << "and" << Sensors[1] << ".\n";
	}

	void setSensorsName(const std::string& sensorName, const int& idx) {
		*Sensors[idx] = sensorName;
	}
};

class Car {
private:
	Engine* engine;
	Brake* brakes;
	Wheel* wheels;
	Sensor* sensors;

public:
	Car(): engine(new Engine), brakes(new Brake[4]), wheels(new Wheel[4]), sensors(new Sensor[2])  {}

	void printParts() {
		engine->print();
		for (int i = 0; i < 4; ++ i) {
			brakes[i].print();
			wheels[i].print();
		}
		
		for (int i = 0; i<2; ++i) {
			sensors[i].print();
		}
	}

	~Car() {
		delete engine;
		delete brakes;
		delete wheels;
		delete sensors;
	}

	Engine* getEngine() const {
		return engine;
	}

	Brake* getBrake() const {
		return brakes;
	}

	Wheel* getWheel() const {
		return wheels;
	}

	Sensor* getSensor() const {
		return sensors;
	}		
};

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