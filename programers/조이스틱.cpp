#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int answer;

void joystick(string word, string name, int cnt, int idx, int dir){
    if(cnt > answer){ return; } // 이미 나온 답 보다 cnt가 크면 return 
    if(word.compare(name) == 0){ answer = min(answer, cnt); }
    
    if(word[idx] != name[idx]){ // 해당 idx자리 문자 변경 없을 경우
        int alpabatIdx = name[idx] - word[idx];
        word[idx] = name[idx];
        joystick(word, name, cnt + alpabatIdx, idx, dir); // 다음 알파벳
        joystick(word, name, cnt + 26 - alpabatIdx, idx, dir); // 이전 알파벳
    }
    else {
        if(dir == 0){ // 커서 오른쪽으로 이동
            joystick(word, name, cnt + 1, (idx + 1) % name.length(), 0);
            joystick(word, name, cnt + 1, (idx + name.length() - 1) % name.length(), 1); // 오른쪽 이동은 중간에 왼쪽으로 이동하는게 더 최소 값 나올 수 있음
        }
        else{ // 커서 왼쪽으로 이동
            joystick(word, name, cnt + 1, (idx + name.length() - 1) % name.length(), 1);
        }
    }
}

int solution(string name) {
    string word = "";
    answer += name.length();
    for(int i=0; i<name.length(); i++){
        word += "A";
        answer += name[i] - 'A'; // 모든 문자를 다음 알파벳으로만 이동 했을 때의 최대 치를 answer에 넣음 >> 나중에 탐색 시 최대 값보다 cnt가 높을 경우 return 하기 위해서
    }

    joystick(word, name, 0, 0, 0); // 오른쪽으로
    joystick(word, name, 0, 0, 1); // 왼쪽으로
    return answer;
}