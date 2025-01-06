/*********************************************************
				2025.01.06
				Yonghee Kim 

				module00 how to use string in cpp. 
                You can use string class's functions(substr, append, insert, replace, erace, etc.)

                    A. Use simple string class
                    B. To convert UPPER CASE
                    C. TO convers LOWER CASE
                
                ./convert {command} {string}
**********************************************************/




#include <iostream>
#include <string>
#include "convert.h"

/*
    int main(int argc, char* argv[]) {}

        argv: argument vector
        argc: argument count: The size of argv
        ./convert {command} {string} 
    
        argv[0] = ./convert
        argv[1] = command
        argv[2] = string

        ls -al
        argv[0] = ls
        argv[1] = -al
*/ 

int main(int argc, char* argv[]) { 


   std::string CaseStr(argv[1]);
   std::string WordStr(argv[2]);

    if (UpperOrNot(CaseStr)) {
        std::string words = LowerToUpper(WordStr);
        std::cout << words << std::endl;
    }

    else if (LowerOrNot(CaseStr)) {
        std::string words = UpperToLower(WordStr);
        std::cout << words << std::endl;        

    }

    else {
        std::cout << "Please put enter command UPPER or LOWER" <<std::endl;
        return 0;
    }

}
