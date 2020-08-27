/*
    1. 1차원 {}으로 나눠서 _tuple에 저장
    2. 원소 갯수가 작은 {}부터 result에 원소를 넣어줘야 하기 때문에 _tuple에 pair 넣어서 first기준으로 오름차순 정렬
    3. find 함수 써서 answer벡터 내에 해당 원소가 존재하는지 여부 판단 >>> 없으면 원소 pushBack
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> answer, temp;
vector<pair <int, vector<int> > > _tuple;
bool flag = false;
string str;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b){ // 원소의 개수를 기준으로 오름차순 정렬
    if(a.first < b.first){ return true; }
    return false;
}

vector<int> solution(string s) {
    int element_cnt = 0; // {}내 원소 개수 세는 변수
    for(int i=1; i<s.length()-1; i++){ // 1번 부분
        if(s[i] == '{'){
            flag = true;
            str = "";
            element_cnt = 0;
        }
        else if(s[i] == '}'){
            flag = false;
            temp.push_back(stoi(str));
            element_cnt++;
            _tuple.push_back(make_pair(element_cnt, temp));
            temp.clear();
        }
        else if(s[i] == ','){
            if(flag){
                temp.push_back(stoi(str));
                str = "";
                element_cnt++;
            }
            else { continue; }
        }
        else{ str += s[i]; }
    }

    sort(_tuple.begin(), _tuple.end(), cmp); // 2번 부분

    for(int i=0; i<_tuple.size(); i++){ // 3번 부분
        for(int j=0; j<_tuple[i].first; j++){
            if(find(answer.begin(), answer.end(), _tuple[i].second[j]) == answer.end()){
                answer.push_back(_tuple[i].second[j]);
            }
        }
    }
    return answer;
}