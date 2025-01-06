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

   switch (Case) {
   case 'UPPER':
    /* code */
    break;
   
   default:
    break;
   }    

}

bool UpperOrLower(char Case) {
    
    if (Case = 'UPPER')
}