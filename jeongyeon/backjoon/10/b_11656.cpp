// 접미사 배열
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
vector<string> res;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    for(int i=0; i<str.length(); i++){
        res.push_back(str.substr(i, str.length()-i));
    }
    sort(res.begin(), res.end());

    for(int i=0; i<res.size(); i++){ cout << res[i] << "\n"; }
    return 0;
}