// N과 M (9)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int N, M;
vector<string> result;
vector<int> arr;
map<string, int> check;
int selected[9];

void dfs(int cnt, string str){
    if(cnt == M){
        if(check.find(str) == check.end()){
            result.push_back(str);
            check.insert({str, 0});
        }
        return;
    }

    for(int i=0; i<N; i++){
        if(selected[i]){ continue; }
        string temp = str;
        temp += to_string(arr[i]);
        temp += " ";
        selected[i] = 1;
        dfs(cnt + 1, temp);
        selected[i] = 0;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    dfs(0, "");
    // sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
    return 0;
}