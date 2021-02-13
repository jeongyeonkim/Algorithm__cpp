// 부당한 퍼즐
// 1. 벡터 뒤에 연결될 숫자들 덧붙임 ex) 1 2 3 4 5 >> 1 2 3 4 5 1 2 3 4 
//          한 번에 연결해서 찾기 위해
// 2. find 함수 > 처음 발견된 숫자 index부터 두 번째 들어오는 수열이랑 비교
// 3. 첫 번째 수열 뒤집어서 1, 2번 반복
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, num;
vector<int> arr, unfair, tmp;

bool puzzle(){
    tmp = arr;
    for(int i=0; i<n-1; i++){ tmp.push_back(arr[i]); }
    int idx = (int)(find(tmp.begin(), tmp.end(), unfair[0]) - tmp.begin());
    for(int i=1; i<n; i++){
        if(unfair[i] != tmp[idx + i]){ return false; }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        arr.push_back(num);
    }
    for(int i=0; i<n; i++){
        cin >> num;
        unfair.push_back(num);
    }

    if(puzzle()){ cout << "good puzzle"; }
    else{
        reverse(arr.begin(), arr.end());
        if(puzzle()){ cout << "good puzzle"; }
        else{ cout << "bad puzzle"; }
    }
    return 0;
}