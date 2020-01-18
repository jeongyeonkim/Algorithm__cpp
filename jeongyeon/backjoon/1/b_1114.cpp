// 통나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, K, C, result1, result2;
vector<int> location;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> L >> K >> C;
    location.push_back(0);
    for(int i=1; i<=K; i++){ cin >> location[i]; }
    location.push_back(L);

    sort(location.begin(), location.end());


}