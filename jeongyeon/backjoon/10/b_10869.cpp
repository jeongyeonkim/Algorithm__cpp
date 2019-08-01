#include <iostream>

int main(void){
    int num1=0;
    int num2=0;
    std::cin >> num1;
    std::cin >> num2;

    std::cout << num1 + num2 << "\n" << num1 - num2 << "\n" << num1*num2 << "\n" << num1/num2 << "\n" << num1%num2;

    return 0;
}