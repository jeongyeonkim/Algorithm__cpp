// 반도체 설계
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> line;

// LIS 사용하면 시간초과남.
// 증가 수열 만듦. 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        int j = lower_bound(line.begin(), line.end(), a) - line.begin();
        
        if(j == line.size()){
            line.push_back(a);
        }else{
            line[j] = a;
        }
    }

    cout << line.size();
}