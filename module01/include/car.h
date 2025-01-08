#pragma once

class car {
public:
    std::string* Make;
    std::string* Model;
    int Year;
    car(const std::string &make, const std::string &model, const int year) {
    Make = new std::string(make);
    Model = new std::string(model);
    Year = year;
    } // 생성자 

    car(const car& other) {
        std::cout << "복사 생성자" << std::endl;
        Make = new std::string(*other.Make);
        Model = new std::string(*other.Model);
        Year = other.Year;
    } // 복사 생성자

    car& operator=(const car& other) {
        std::cout << "복사 대입 연산자" << std::endl;
        if (this == &other) { // this가 포인터로 type이 car*이다 그래서 &other로 해줘야 됨
            return *this;
        }

        delete Make;
        delete Model;

        Make = new std::string(*other.Make);
        Model = new std::string(*other.Model);  
        Year = other.Year;
        return *this;      
    } // 복사 대입 연산자

    ~car() {
        delete Make;
        delete Model;
    } // 소멸자

    void drive() {
        std::cout << "Make: " << *Make << "\tModel: " << *Model << "\tYear: " << Year << std::endl;
    };
};

class sportsCar : car {
public:
    int topSpeed;
    sportsCar(const std::string &make, const std::string &model, const int year, const int topspeed)
    : car(make, model, year), topSpeed(topspeed) { }

    sportsCar(const sportsCar& other)
    :car(other), topSpeed(other.topSpeed) { }

    sportsCar& operator = (const sportsCar& other) {
        if (this == &other) {
            return *this;
        }

        car::operator=(other);
        topSpeed = other.topSpeed;

        return *this;
    }

    ~sportsCar() {
        // 부모 class에서 이미 해제 했으므로 따로 필요없음
    }

    void drive() {
        car::drive();
        std::cout << "Speed:\t" << topSpeed << std::endl;
        
    }
};

