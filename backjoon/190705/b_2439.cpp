#include <iostream>

int main(void){
    int star=0;
    std::cin >> star;

    for(int i=1; i <= star; i++){
        for(int j=0; j< star-i; j++)
            std::cout <<" ";
        for(int j=0; j <i; j++)
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}