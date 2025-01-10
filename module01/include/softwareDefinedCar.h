#pragma once

class softwareDefinedCar {
private:
    int AutonomousDrivingLevel; // 0~5
    int Electrification; // 1~100
    bool Connectivity;
    bool OverTheAir;

public:
    std::string* Make;
    std::string* Model;
    int Year;

    softwareDefinedCar(const std::string &make, const std::string &model, const int year) {
        Make = new std::string(make);
        Model = new std::string(model);
        Year = year;
    } 

    softwareDefinedCar(const softwareDefinedCar& other) {
        Make = new std::string(*other.Make);
        Model = new std::string(*other.Model);
        Year = other.Year;
    }

    softwareDefinedCar& operator=(const softwareDefinedCar& other) {
        if (this == &other) {
            return *this;
        }
        delete Make;
        delete Model;

        Make = new std::string(*other.Make);
        Model = new std::string(*other.Model);
        Year = other.Year;
        return *this;
    }

    virtual void printOtaInfo() const { 
    /*

    virtual로 선언해서 다른 상속 cls에서 이를 수정할 수 있음 
    상속받은 cls의 printInfo가 overriding없이 적고 void printInfo {}로 const없이 작성해서 형식이 틀리다면 컴파일 에러는 안뜨지만 
    수정된 printInfo가 아닌 부모 cls printInfo를 따름 이 virtual은 runtime시 확인하는데 이를 overriding을 써주면 형태가 다르면 다르다고 알려줌

    */
        std::cout << "OTA!, Current SDV can upgradable." << std::endl;
    }

    virtual void drive() const {
        std::cout << "\nAutonomous Driving Level: " << AutonomousDrivingLevel << "\tElectrification: " \
        << Electrification << "\tConnectivity: " << Connectivity << "\tOTA: " << OverTheAir << std::endl;
        std::cout << "Make: " << *Make << "\tModel: " << *Model << "\tYear: " << Year << std::endl;
    };

    void setAutonomousDrivingLevel(const int& level) {
        AutonomousDrivingLevel = level;
    }

    void setElecrification(const int& level) {
        Electrification = level;
    }

    void setConnectivitiy(const bool& isConnect) {
        Connectivity = isConnect;
    }

    void setOverTheAir(const bool& isOTA) {
        OverTheAir = isOTA;
    }

    int getAutonomousDrivingLevel() const { // const안 붙이면 컴파일러가 해당 함수가 객체의 상태를 변경할 가능성이 있다고 판단해서 호출 못함
                                            // const로 선언된 멤버 함수만 호출할 수 있다.
        return AutonomousDrivingLevel ;
    }

    int getElecrification() const {
        return Electrification;
    }

    bool getConnectivitiy() const {
        return Connectivity;
    }

    bool getOverTheAir() const {
        return OverTheAir;
    }
    ~softwareDefinedCar() {
        delete Make;
        delete Model;
    }

};

class softwareDefinedCarLidar : public softwareDefinedCar { // 상속시 public 명시하지 않으면 멤버들이 private으로 들어감 부모 cls로 자식 cls 접근하려면 public으로 ㄱㄱ
public:
    std::string* Lidar;

    softwareDefinedCarLidar(const std::string &make, const std::string &model, const int year, const std::string &lidar) 
    : softwareDefinedCar(make, model, year) {
        Lidar = new std::string(lidar);
    }

    softwareDefinedCarLidar(const softwareDefinedCarLidar& other)
    : softwareDefinedCar(other), Lidar(other.Lidar) {}

    softwareDefinedCarLidar& operator=(const softwareDefinedCarLidar& other) {
        if (this == &other) {
            return *this;
        }

        softwareDefinedCar::operator=(other);
        Lidar = other.Lidar;

        return *this;
    }

    void printOtaInfo() const override {
        std::cout << "OTA!, Current SDV can't upgradable." << std::endl;
    }

    void drive() const override {
        std::cout << "\nLidar is mounted in this vehicle" << std::endl;        
        std::cout << "Autonomous Driving Level: " << getAutonomousDrivingLevel() << "\tElectrification: " \
        << getElecrification() << "\tConnectivity: " << getConnectivitiy() << "\tOTA: " << getOverTheAir() << std::endl;
        std::cout << "Make: " << *Make << "\tModel: " << *Model << "\tYear: " << Year << "\tLiDAR: " << *Lidar << std::endl;
    }

    ~softwareDefinedCarLidar() {}
};

class softwareDefinedCarCamera : public softwareDefinedCar {
public:
    std::string* Camera;

    softwareDefinedCarCamera(const std::string &make, const std::string &model, const int year, const std::string &camera) 
    : softwareDefinedCar(make, model, year){
        Camera = new std::string(camera);
    }

    softwareDefinedCarCamera(const softwareDefinedCarCamera& other)
    : softwareDefinedCar(other), Camera(other.Camera) {}

    softwareDefinedCarCamera& operator=(const softwareDefinedCarCamera& other) {
        if (this == &other) {
            return *this;
        }
        softwareDefinedCar::operator=(other);
        Camera = other.Camera;
        return *this;
    }

    void printOtaInfo() const override {
        std::cout << "OTA!, Current SDV can upgradable but limited." << std::endl;
    }

    void drive() const override {
        std::cout << "\nCamera is mounted in this vehicle" << std::endl;
        std::cout << "Autonomous Driving Level: " << getAutonomousDrivingLevel() << "\tElectrification: " \
        << getElecrification() << "\tConnectivity: " << getConnectivitiy() << "\tOTA: " << getOverTheAir() << std::endl;
        std::cout << "Make: " << *Make << "\tModel: " << *Model << "\tYear: " << Year << "\tCamera: " << *Camera << std::endl;
    }

    ~softwareDefinedCarCamera() {}
};