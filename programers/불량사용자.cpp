/* 
    1. 불량 사용자 가능한 조합 -> dfs + 백트래킹
    2. 조합 만든 후 중복 처리 -> map 사용
    3. 중복처리를 위해 사용한 user_id index를 vector에 저장
    4. 저장 후 sort 처리
    5. 정렬 후 해당 값 string으로 만들어서 map에 push
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int answer;
int used[9];
map<string, int> result;

bool checkUser(string user_id, string banned_id){ // 불량 사용자인지 체크하는 함수
    if(user_id.length() != banned_id.length()){ return false; }

    for(int i=0; i<user_id.length(); i++){
        if(banned_id[i] == '*'){ continue; }
        if(banned_id[i] != user_id[i]){ return false; }
    }
    return true;
}

void bad_user(int cnt, vector<string> user_id, vector<string> banned_id, vector<int> tmp){
    if(cnt == banned_id.size()){
        string str = "";
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<tmp.size(); i++){ str += to_string(tmp[i]); }
        if(result.find(str) == result.end()){
            result.insert(make_pair(str, 0));
            answer++;
        }
        
        return;
    }

    for(int i=0; i<user_id.size(); i++){ // 가능한 조합 만들기
        if(!used[i] && checkUser(user_id[i], banned_id[cnt])){
            used[i] = 1;
            tmp.push_back(i);
            bad_user(cnt + 1, user_id, banned_id, tmp);
            used[i] = 0; 
            tmp.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> tmpList;
    bad_user(0, user_id, banned_id, tmpList);
    return answer;
}