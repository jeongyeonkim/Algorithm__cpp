#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int num=0;
    cin >> num;
    int arr[num];

    for(int i=0; i<num; i++){
        cin >> arr[i];
    }
    sort(arr, arr+num);
    for(int i=0; i<num; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}