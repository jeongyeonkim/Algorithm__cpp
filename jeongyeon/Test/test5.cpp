#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<pair <int, string>> res;
map<string, int> arr;

bool cmp(const pair<int, string> &a, const pair<int, string> &b){
    return a.first > b.first;
}


vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<string> answer;
    for(int i=0; i<tags.size(); i++){ arr.insert(make_pair(tags[i], 1)); }
    for(int i=0; i<dataSource.size(); i++){
        if(dataSource[i].size() > 1){
            int cnt = 0;
            for(int j=1; j<dataSource[i].size(); j++){
                if(arr.find(dataSource[i][j]) != arr.end()){ cnt++; }
            }
            if(cnt > 0){ res.push_back(make_pair(cnt, dataSource[i][0])); }
        }
    }

    sort(res.begin(), res.end(), cmp);
    for(int i=0; i<res.size(); i++){ answer.push_back(res[i].second); }
    return answer;
}