// 비슷한 단어
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int N, result;
string inputWord;
int alpabat[28], temp[28];

void copyAlPABAT(){
    for(int i=0; i<27; i++){ temp[i] = alpabat[i]; }
}

int main(void){
    cin >> N;
    cin >> inputWord;
    for(int i=0; i<inputWord.length(); i++){
        alpabat[inputWord[i] - 'A']++;
    }

    for(int i=0; i<N-1; i++){
        string str; cin >> str;
        if(abs((int)(str.length() - inputWord.length())) > 1){ continue; } // 길이 차이가 1 이상이면 비슷한 단어가 될 수 없음.
        bool check = true, flag = true;
        copyAlPABAT();

        for(int j=0; j<str.length(); j++){
            if(temp[str[j] - 'A'] <= 0){
                if((int)(inputWord.length() - str.length()) > 0){ check = false; break; } // 비교 문자가 초기 문자보다 길이가 작을 경우, 다른 단어 대체 X
                if(flag){ flag = false; }
                else{ check = false; break; }
            }
            else { temp[str[j] - 'A']--; }
        }
        if(check){ result++; }
    }

    cout << result;
    return 0;
}