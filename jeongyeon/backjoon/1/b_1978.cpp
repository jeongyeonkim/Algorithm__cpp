#include <iostream>
using namespace std;

int main(){
    int num=0;
    cin >> num;
    int arr[num], count=0;
    
    for(int i=0; i<num; i++){
        cin >> arr[i];
        for(int j=2; j<=arr[i]; j++){
            if((arr[i] % j) == 0){
                if(arr[i] == j){
                    count++;
                }else{
                    break;
                }
                
            }
        }
    }
    cout << count;
    return 0;
}