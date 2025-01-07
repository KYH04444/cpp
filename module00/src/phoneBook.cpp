#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "phoneBook.h"

int main(int argc, char* argv[]) {
    PhoneBook phoneBook;
    int optionNumber = 0;
    std::string Name;
    double PhoneNumber;
    std::string Nickname;
    
    std::cout << "---------------------------Phone Book---------------------------" << std::endl;

    while (optionNumber != 5)
    {
        std::cout << "-----------------------Choose the options-----------------------" << std::endl;
        std::cout << "1. ADD\t" << "2. SEARCH\t" << "3. REMOVE\t" << "4. BOOKMARK\t" << "5. EXIT\t" << std::endl; 
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cin >> optionNumber;
        std::cout << "----------------------------------------------------------------" << std::endl;
        if (optionNumber == 1) {
            
            std::cout << "Type Name" <<std::endl;
            std::cin >> Name;
            std::cout << "Type Phone number" <<std::endl;
            std::cin >> PhoneNumber;
            std::cout << "Type Nick name" <<std::endl;
            std::cin >> Nickname;
            for(int i = 0; i < phoneBook.getList().size(); ++i) {
                if (phoneBook.getList()[i].getPhoneNumber() == PhoneNumber) {
                    std::cout << "This number is already added in the phone book. Try again" << std::endl;
                    std::cout << "Type Name" <<std::endl;
                    std::cin >> Name;
                    std::cout << "Type Phone number" <<std::endl;
                    std::cin >> PhoneNumber;
                    std::cout << "Type Nick name" <<std::endl;
                    std::cin >> Nickname;
                }
            }
            phoneBook.Add(Name,PhoneNumber,Nickname);
        }

        else if (optionNumber == 2) {
            phoneBook.Search();
        }

        else if (optionNumber == 3) {
            double idx;
            for (int i = 0; i < phoneBook.getList().size(); ++ i) {
            std::cout << i+1 << "\t" << phoneBook.getList()[i].getName() << "\t" << std::fixed << std::setprecision(0) << phoneBook.getList()[i].getPhoneNumber() << std::endl;
        }
            std::cout << "if you want to remove a contact, Type index or phone number." << std::endl;
            std::cin >> idx; 
            phoneBook.Remove(idx);
        }

        else if (optionNumber == 4) {
            phoneBook.Bookmark();
        }

        else if (optionNumber == 5) {
            phoneBook.Exit();
        }
    }
}