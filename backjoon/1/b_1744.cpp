// 수 묶기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int N;
vector<int> arr;
long long result;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        arr.push_back(input);
        result += input;
    }
    bool seleted[N+1];
    memset(seleted, 0, sizeof(seleted));
    if(N == 1){
        cout << arr[0];
        return 0;
    }
    long long temp = 0;
    sort(arr.begin(), arr.end());

    for(int i=N-1; i>0; i--){ // 양수끼리 곱, 1은 곱하기보다 더하는게 더 큰 수
        if(seleted[i]){ continue; }
        if(arr[i] > 1 && arr[i-1] > 1){
            seleted[i] = true;
            seleted[i-1] = true;
            temp += arr[i] * arr[i-1];
        }
        else{ break; }
    }

    int idx = -1;
    for(int i=0; i<N-1; i++){
        if(seleted[i]){ continue; }
        if(arr[i] <= 0 && arr[i+1] <= 0){
            seleted[i] = true;
            seleted[i+1] = true;
            temp += arr[i] * arr[i+1];
        }
    }

    for(int i=0; i<N; i++){
        if(!seleted[i]){ temp += arr[i]; }
    }

    result = max(result, temp);
    cout << result;
    return 0;
}