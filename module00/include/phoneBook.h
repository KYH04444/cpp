#pragma once

class People { // 민찬이가 struct 잘 안쓴다고 쓰지말라고 함 class 쓰자
private:
    std::string Name;
    double PhoneNumber;
    std::string Nickname;

public:
    People(const std::string& newName, double newPhoneNumber, const std::string& newNickname)
        : Name(newName), PhoneNumber(newPhoneNumber), Nickname(newNickname) 
    {}
// private에 선언된 멤버변수에 접근하기 위한 method
    std::string getName() const { return Name; }
    double getPhoneNumber() const { return PhoneNumber; }
    std::string getNickname() const { return Nickname; }

};

class PhoneBook {
private:
    std::vector<People> list; // People class형태의 vector 생성
    std::vector<People> BookMark;

public:
    std::vector<People> getList() {
        return list;
    }

    void Add(const std::string& Name, const double PhoneNumber, const std::string& Nickname) { // std::string& Name으로 받으면 copy 안하고 수정 가능
        list.push_back(People(Name, PhoneNumber, Nickname)); 
        std::cout << Name << "  is added in the Phone book." << std::endl;
    }

    void Search() {
        int idx = 0;
        int bookmark = 0;
        for (int i = 0; i < list.size(); ++ i) {
            std::cout << i+1 << "\t" << list[i].getName() << std::endl;
        }
            std::cout << "if you want to show details, Choose number, else press 0." << std::endl;
        std::cin >> idx;
        if (idx != 0) {
            std::cout << list[idx-1].getName() << "\t" << std::fixed << std::setprecision(0) << list[idx-1].getPhoneNumber() << "\t" << list[idx-1].getNickname() << std::endl;
            std::cout << "if you want to bookmark the contact, press 1, else press 0." << std::endl; // std::fixed << std::setprecision(0)를 안쓰면 1012345678이 10e7 이런식으로 나옴 
            std::cin >> bookmark;
            if (bookmark == 1) {
                BookMark.push_back(list[idx-1]);
            }
        }
    }

    void Remove(double phoneNumber) {
        while (phoneNumber != 0) {
            if (phoneNumber > 91764075) {
                int findIdx = 0;
                for (int i = 0; i <list.size(); ++i) {
                    if (list[i].getPhoneNumber() == phoneNumber) {
                        findIdx = i;
                        list.erase(list.begin() + findIdx);
                        phoneNumber = 0;
                        break;
                    }
                    else {
                        std::cout << "There is no matching phone number, Please Type a right number. If you want to go back, Type 0" << std::endl;
                        std::cin >> phoneNumber;
                    }
                }
                
            }

            else {
                list.erase(list.begin() + phoneNumber);
                phoneNumber = 0;
                break;
            }
        }
        
    }

    void Bookmark() {
        for(int i = 0; i <BookMark.size(); ++i) {
            std::cout << BookMark[i].getName() << "\t" << std::fixed << std::setprecision(0) << BookMark[i].getPhoneNumber() << "\t" << BookMark[i].getNickname() << std::endl;
        }
    }

    void Exit() {
        std::cout << "Exit" << std::endl;
    }

};