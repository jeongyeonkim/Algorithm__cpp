// 듣보잡
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
string str;
map<string, int> arr;
vector<string> result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> str;
        arr.insert(make_pair(str, 1));
    }

    for(int i=0; i<M; i++){
        cin >> str;
        if(arr.find(str) != arr.end()){ result.push_back(str); }
    }
    sort(result.begin(), result.end());
    
    cout << result.size() << "\n";
    for(int i=0; i<result.size(); i++){ cout << result[i] << "\n"; }
    return 0;
}