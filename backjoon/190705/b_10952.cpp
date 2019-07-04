#include <iostream>

int main(void){
    int num1, num2;

    while(std::cin >> num1 >> num2){
        if(num1 == 0 && num2 == 0)
            break;
        std::cout << num1+num2 <<"\n";
    }

    return 0;
}