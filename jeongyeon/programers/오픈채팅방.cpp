#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
vector<pair <string, int>> result; // 0 = 입장, 1 = 퇴장
map<string, string> userID;

vector<string> spiltString(string str, char ch){ // 문자열 자르기
    vector<string> temp;
    istringstream ss(str);
    string s;
    while (getline(ss, s, ch)){
        temp.push_back(s);
    }
    return temp;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(int i=0; i<record.size(); i++){
        vector<string> spilt = spiltString(record[i], ' ');

        if(spilt[0].compare("Enter") == 0){
            if(userID.find(spilt[1]) == userID.end()){ // 등록되지 않은 userid일 경우 
                userID.insert(make_pair(spilt[1], spilt[2])); // {아이디, 아름}
            }
            else{ userID[spilt[1]] = spilt[2]; } // 이미 있는 userid일 경우 이름이 바뀌었을 수 있으니 이름 갱신

            result.push_back(make_pair(spilt[1], 0)); // ~~님이 들어왔습니다.
        }
        else if(spilt[0].compare("Leave") == 0){
            result.push_back(make_pair(spilt[1], 1)); // ~~님이 나갔습니다.
        }
        else if(spilt[0].compare("Change") == 0){ // 이름 변경할 경우
            userID[spilt[1]] = spilt[2];
        }
    }
    
    for(int i=0; i<result.size(); i++){
        string name = userID[result[i].first]; // 이름 검색
        
        if(result[i].second == 0){ // 입장
            answer.push_back(name + "님이 들어왔습니다.");
        }
        else if(result[i].second == 1){ // 퇴장
            answer.push_back(name + "님이 나갔습니다.");
        }
    }
    return answer;
}