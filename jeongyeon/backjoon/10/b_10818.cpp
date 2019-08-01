#include <iostream>

int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(false);
    std::cout.tie(false);

    int n=0;
    std::cin >> n;
    int max=-1000000;
    int min=1000000;

    int input[n];
    for(int i=0; i<n; i++)
        std::cin >> input[i];
    
   for(int j=0; j<n; j++){
        if(max < input[j])
            max = input[j];
        if(min > input[j])
            min = input[j];
    }

    std::cout << min << " " << max;
    return 0;
}