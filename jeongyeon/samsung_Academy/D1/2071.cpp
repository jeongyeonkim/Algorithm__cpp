#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t=0, k=1;    cin >> t;
    int result[t+1];
    result[0]=0;

    while(t--){
        int arr[10];
        double avg=0;
        for(int i=0; i<10; i++){
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= 10;
        avg = round(avg/10.0);
        result[k] = (int)avg;
        k++;
    }
    for(int i=1; i<=t; i++)
        cout << "#" << i << " " << result[i];
    return 0;
}