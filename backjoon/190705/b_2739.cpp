#include <iostream>

int main(void){
    int n=0;
    std::cin >> n;

    for(int i=1;i<=9;i++){
        std::cout << n << " * " << i << " = " << n*i << "\n";
    }
    
    return 0;
}