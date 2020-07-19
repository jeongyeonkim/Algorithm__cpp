// 센서
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, result;
vector<int> arr, solve;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());

    for(int i=0; i<N-1; i++){ // 앞의 센서와 거리구해서 정렬
        solve.push_back(arr[i+1] - arr[i]);
    }
    sort(solve.begin(), solve.end());

    for(int i=N-K-1; i>=0; i--){ // 긴 길이를 갖는 센서 자리부터 지워나감
        result += solve[i];
    }

    cout << result;
    return 0;
}