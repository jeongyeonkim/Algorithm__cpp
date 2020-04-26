#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
int num[MAX];
vector<pair<int, int>> result;

vector<int> solution(string s) {
    vector<int> answer;
    bool check = false;
    string temp = ""; temp += s[2];
    for(int i=3; i<s.length()-1; i++){
        if(s[i] >= 48 && s[i] <= 57){
            temp += s[i];
        }else{
            if(temp.length() > 0){
                std::stringstream ss(temp);
                int n; ss >> n;
                num[n]++;
                temp = "";
            }
        }
    }
    
    for(int i=1; i<MAX; i++){
        if(num[i] > 0){
            result.push_back(make_pair(num[i], i));
        }
    }
    sort(result.begin(), result.end());
    
    for(int i=result.size()-1; i>=0; i--){
        answer.push_back(result[i].second);
    }
    return answer;
}