// 통계학
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, maxNum = -4001, minNum = 4001; 
// arr : 양수 값 빈도 수 저장, arrNega : 음수 값 빈도 수 저장
int arr[4001], arrNega[4001];
double sum;
vector<int> num;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    int k = 0;
    for(int i=0; i<N; i++){
        cin >> k;
        sum += k;
        maxNum = max(maxNum, k);
        minNum = min(minNum, k);
        if(k > 0){ arr[k]++; }
        else{ arrNega[k*(-1)]++; }
        num.push_back(k);
    }
    
    // 최빈값 찾기
    vector<int> findH;
    int MAX = 0, temp = -1;
    // 절대값 중 최대 까지 조회
    if(maxNum > abs(minNum)){ MAX = maxNum; }
    else{ MAX = abs(minNum); }

    for(int i=0; i<=MAX; i++){
        if(temp == arr[i]){ findH.push_back(i); }
        if(temp < arr[i]){
            temp = arr[i];
            findH.clear();
            findH.push_back(i);
        }
        if(temp == arrNega[i]){ findH.push_back(i*(-1)); }
        if(temp < arrNega[i]){
            temp = arrNega[i];
            findH.clear();
            findH.push_back(i*(-1));
        }
    }
    
    sort(findH.begin(), findH.end());
    sort(num.begin(), num.end());

    // 산술 평군
    cout << round(sum/N) << "\n";
    // 중앙 값 (정렬 한뒤)
    cout << num[N/2] << "\n";
    // 최빈 값
    if(findH.size() >= 2){ cout << findH[1] << "\n"; }
    else{ cout << findH.front() << "\n"; }
    // 범위
    cout << maxNum - minNum;
}