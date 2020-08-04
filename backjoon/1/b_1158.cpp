// 요세푸스 문제
#include <iostream>
#include <vector>
using namespace std;
int N, K, temp;
vector<int> arr, res;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){ arr.push_back(i); }

    while (!arr.empty()){
        temp = (temp + K - 1) % arr.size();
        res.push_back(arr[temp]);
        arr.erase(arr.begin() + temp);
    }

    cout << "<";
    for(int i=0; i<res.size()-1; i++){
        cout << res[i] <<", ";
    }
    cout << res[N-1] << ">";
    
} 