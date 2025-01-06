/*********************************************************
				2025.01.06
				Yonghee Kim 

				module00 how to use string in cpp. 
                
                To convert UPPER CASE
                TO convers LOWER CASE
                
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

    if (UpperOrNot(CaseStr)) { // Upper case인지 아닌지 확인 하기 위한 function
        std::string words = LowerToUpper(WordStr); // str을 읽어 이를 ASCII code 계산하여 Lower to Upper
        std::cout << words << std::endl;
    }

    else if (LowerOrNot(CaseStr)) { // Lower case인지 아닌지 확인 하기 위한 function
        std::string words = UpperToLower(WordStr); // str을 읽어 이를 ASCII code 계산하여 Upper to Lower 
        std::cout << words << std::endl;        

    }

    else {
        std::cout << "Please put enter command UPPER or LOWER" <<std::endl;
        return 0;
    }

}
