#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int start_time = 540;
    vector<int> arrive_time;
    for(int i=0; i<timetable.size(); i++){ // 모든 시간 분으로 바꿔서 int형으로
        int _h = stoi(timetable[i].substr(0, 2));
        int _m = stoi(timetable[i].substr(3, 2));
        arrive_time.push_back(_h * 60 + _m);
    }
    sort(arrive_time.begin(), arrive_time.end()); // 먼저 도착하는 크루부터 정렬
    int idx = 0, cnt = 0;

    while(true){
        int boarding = m;
        for(int i=idx; i<arrive_time.size(); i++){
            if(start_time >= arrive_time[i]){
                boarding--;
                idx++;
            }
            if(boarding == 0){ break; } // 최대 승차수가 넘어가면 for문 break;
        }

        n--;
        if(n <= 0){
            if(boarding <= 0){ start_time = arrive_time[idx-1] - 1; }
            break;
        }
        start_time += t;
    }
    
    //결과 형식에 맞추어 변환
    if(start_time / 60 < 10){ answer += "0"; }
    answer += to_string(start_time/60);
    answer += ":";
    if(start_time % 60 < 10){ answer += "0"; }
    answer += to_string(start_time % 60);
    return answer;
}