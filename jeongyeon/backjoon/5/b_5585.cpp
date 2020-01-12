//거스름돈
#include <iostream>
using namespace std;
int N, result;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    N = 1000-N;
    int arr[7]= {500, 100, 50, 10, 5, 1};

    for(int i=0; i<6; i++){
        result += N/arr[i];
        N = N%arr[i];
    }

    cout << result;
}