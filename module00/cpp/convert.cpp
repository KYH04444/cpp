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

bool UpperOrNot(char* Case) {
    bool upper = false;
    char* bagOfUpperCase[] = {"upper", 
                              "uppeR", 
                              "uppEr", "uppER", 
                              "upPer", "upPeR", "upPEr", "upPER", 
                              "uPper", "uPpeR", "uPpEr", "uPpER", "uPPer", "uPPeR", "uPPEr", "uPPER", 
                              "Upper", "UppeR", "UppEr", "UppER", "UpPer", "UpPeR", "UpPEr", "UpPER", "UPper", "UPpeR", "UPpEr", "UPpER", "UPPer", "UPPeR", "UPPEr", "UPPER"};
    
    for(int i = 0; i <sizeof(bagOfUpperCase); i++) {
        if(bagOfUpperCase[i] = Case) {
            upper = true;
            return upper;
        }
    }

return upper;
}

bool LowerOrNot(char* Case) {
    bool lower = false;
    char* bagOfLowerCase[] = {"lower", 
                              "loweR", 
                              "lowEr", "lowER", 
                              "loWer", "loWeR", "loWEr", "loWER", 
                              "lOwer", "lOweR", "lOwEr", "lOwER", "lOWer", "lOWeR", "lOWEr", "lOWER", 
                              "Lower", "LoweR", "LowEr", "LowER", "LoWer", "LoWeR", "LoWEr", "LoWER", "LOwer", "LOweR", "LOwEr", "LOwER", "LOWer", "LOWeR", "LOWEr", "LOWER"};
    
    for(int i = 0; i <sizeof(bagOfLowerCase); i++) {
        if(bagOfLowerCase[i] = Case) {
            lower = true;
            return lower;
        }
    }

return lower;
}

char UpperToLower(char* str, int size) {
    for (int i = 0; i < size; i++) {
        if (str[i])
    }
}

int main(int argc, char* argv[]) { 
    // argv: argument vector
    // argc: argument count: The size of argv
    /*
        ./convert {command} {string} 
        argv[0] = ./convert
        argv[1] = command
        argv[2] = string

        ls -al
        argv[0] = ls
        argv[1] = -al
    */ 
   char Case = *argv[1];

    if (UpperOrNot(&Case)) {

    }

    else if (LowerOrNot(&Case)) {

    }

    else {
        std::cout << "Please put enter command UPPER or LOWER" <<std::endl;
        return 0;
    }


}
