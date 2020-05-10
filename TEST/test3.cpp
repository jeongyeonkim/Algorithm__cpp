#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
map<string, int> arr;
int r, l;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int idx = 0;
    for(int i=0; i<gems.size(); i++){
        if(arr.find(gems[i]) == arr.end()){
            arr.insert(make_pair(gems[i], idx++));
        }
    }
    int mapSize = arr.size();
    r = mapSize;
    int dp[gems.size()+1][arr.size()+1];
    memset(dp, 0, sizeof(dp));
    dp[1][arr[gems[0]]] = 1;
    for(int i=0; i<gems.size(); i++){
        for(int j=0; j<mapSize; j++){
            if(j == arr[gems[i]]){ dp[i][arr[gems[i]]] = dp[i-1][arr[gems[i]]] + 1; }
            else{ dp[i][j] = dp[i-1][j]; }
        }
    }
    for(int i=0; i<gems.size(); i++){
        for(int j=0; j<i; j++){
            bool check = true;
            cout << j << " " << i << "\n";
            for(int k=0; k<mapSize; k++){ cout << dp[i][k] - dp[j][k] << " ";
                if(dp[i][k] - dp[j][k] <= 0){ check = false; }
            }cout << "\n";
            if(check && r-l > i - j){
                    r = i;
                    l = j;
            }
        }
    }
    answer.push_back(l+1);
    answer.push_back(r);
    return answer;
}

int main(){
    vector<string> arr;
    arr.push_back("AA");
    arr.push_back("AB");
    arr.push_back("AC");
    arr.push_back("AA");
    arr.push_back("AC");
    solution(arr);
}