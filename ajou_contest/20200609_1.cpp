#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, L, N, result = 1;
vector<int> arr;

int main(void){
    cin >> M >> L >> N;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int cnt = arr[0] + L;

    for(int i=1; i<arr.size(); i++){
        if(cnt == L){
            cnt += arr[i];
            continue;
        }
        if(arr[i] > cnt){
            result++;
            cnt = arr[i] + L;
        }
        else if(arr[i] == cnt){
            result++;
            cnt = L;
        }
    }
    cout << result;
    return 0;
}