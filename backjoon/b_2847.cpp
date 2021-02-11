// 게임을 만든 동준이
#include <iostream>
#include <vector>
using namespace std;
int N, result, temp;
vector<int> arr;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    temp = arr[N-1];
    for(int i=N-2; i>=0; i--){
        while (temp <= arr[i]){
            arr[i]--;
            result++;
        }
        
        
        temp = arr[i];
    }

    cout << result;
    return 0;
}