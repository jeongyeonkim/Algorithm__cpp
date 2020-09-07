#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
using namespace std;
long long answer;
deque<string>  deqNum, tmpNum;
deque<char> deqMath, tmpMath;
string num;
int cntMath[3], tmpCntMath[3], selected[3], visited[3];
char _math[3] = {'+', '-', '*'};

long long cal(char ch, long long num1, long long num2){
    if(ch == '+'){ return num1 + num2; }
    else if(ch == '-'){ return num1 - num2; }
    else{ return num1 * num2; }
}

void findMaxResult(){
    for(int i=0; i<3; i++){
        while (tmpCntMath[selected[i]] > 0) {
            if(_math[selected[i]] == tmpMath.front()){
                tmpMath.pop_front();
                string num1 = tmpNum.front(); tmpNum.pop_front();
                string num2 = tmpNum.front(); tmpNum.pop_front();
                //tmpNum.push_back(to_string(cal(_math[selected[i]], stol(num1), stol(num2))));
                tmpNum.push_front(to_string(cal(_math[selected[i]], stol(num1), stol(num2))));
                tmpCntMath[selected[i]]--;
            }else {
                tmpMath.push_back(tmpMath.front());
                tmpMath.pop_front();
                tmpNum.push_back(tmpNum.front());
                tmpNum.pop_front();
            }
        }
    }
    if(answer < abs(stol(tmpNum.front()))){
        answer = abs(stol(tmpNum.front()));
    }
}

void select(int cnt){
    if(cnt == 3){
        tmpNum = deqNum; tmpMath = deqMath;
        for(int i=0; i<3; i++){ tmpCntMath[i] = cntMath[i]; }
        findMaxResult();
        return;
    }
    for(int i=0; i<3; i++){
        if(visited[i]){ continue; }
        visited[i] = 1;
        selected[cnt] = i;
        select(cnt + 1);
        visited[i] = 0;
    }
}

long long solution(string expression) {
    for(int i=0; i<expression.length(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            deqNum.push_back(num);
            deqMath.push_back(expression[i]);
            num = "";
            if(expression[i] == '+'){ cntMath[0]++; }
            else if(expression[i] == '-'){ cntMath[1]++; }
            else if(expression[i] == '*'){ cntMath[2]++; }
        }
        else { num += expression[i]; }
    }
    deqNum.push_back(num);
    selected[0] = 2;
    selected[1] = 0;
    selected[2] = 1;
    tmpNum = deqNum; tmpMath = deqMath;
    for(int i=0; i<3; i++){ tmpCntMath[i] = cntMath[i]; }
    findMaxResult();
    //select(0);
    return answer;
}