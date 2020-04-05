#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
stack<char> arr[4];
int cnt[4];
char a[4] = {'(', '{', '[', '<'};
char b[4] = {')', '}', ']', '>'};

int solution(string inputString) {
    int answer = -1;
    bool resNot = true;
    for(int i=0; i<inputString.length(); i++){
        for(int j=0; j<4; j++){
            if(inputString[i] == a[j]){
                arr[j].push(inputString[i]); 
                break;
            }
        }
        for(int j=0; j<4; j++){
            if(inputString[i] == b[j]){
                if(!arr[j].empty()){
                    arr[j].pop();
                    cnt[j]++;  
                    break;                      
                }else{ resNot = false; }
            }
        }
    }

    if(resNot){ answer = cnt[0] + cnt[1] + cnt[2] + cnt[3]; }
    return answer;
}