// 회사에 있는 사람
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n;
vector<string> arr;
set<string> sss;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        string s, v;
        cin >> s >> v;
        if(v == "enter") {sss.insert(s);
        } else { sss.erase(s); }
    }
 
    for (auto it = sss.begin(); it != sss.end(); ++it) { arr.push_back(*it); }
 
    reverse(arr.begin(), arr.end());
 
    for(int i = 0; i < arr.size(); i ++) { cout << arr[i] << "\n"; }
    return 0;
}