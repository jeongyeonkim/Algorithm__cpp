#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1001;
    int cnt = 0;
    
    while(cnt <= s.length()/2){ // 압축 단위는 최대 문자열 길이의 1/2
        cnt++; // cnt == 압축 단위(길이)
        int idx = 0;
        string result = "";
        string before = s.substr(0, cnt);
        int beforeCnt = 1;
        
        while(idx < s.length()){
            if(idx + cnt >= s.length()){ // 남은 문자열 처리
                if(beforeCnt > 1){ result += to_string(beforeCnt); }
                result += before;
                break;
            }

            idx += cnt;
            if(!s.substr(idx, cnt).compare(before)){ // 이전 문자열과 같을 경우
                beforeCnt++;
            }else{ // 다를 경우
                if(beforeCnt > 1){ result += to_string(beforeCnt); }
                result += before;
                beforeCnt = 1; // 이전 문자열 현재 문자열로 변환
                before = s.substr(idx, cnt);
            }
        }
        
        answer = min(answer, (int)result.length());
    }
    
    return answer;
}