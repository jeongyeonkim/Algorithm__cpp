// 316
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int alpabatLastIndex[26];

// 4ms 6.5MB
// 1. 알파벳 각각의 마지막 인덱스 저장
// 2. s 인덱스 탐색하면서 해당 인덱스 이전에 나온 문장에서
//        자신보다 작은 알파벳 && 뒤에 또 나오는 알파벳이면 지우기
// 3. 인덱스 -1 위치 부터 2번 조건 판별하면서 하나씩 지우기 >> 2조건 해당되지 않으면 while문 탈출
// 4. ex) acdk일 경우 b입력 시 ac 지워버리면 dkb 되기 때문에

string removeDuplicateLetters(string s) {
    for(int i=0; i<s.length(); i++){
        alpabatLastIndex[s[i] - 'a'] = max(alpabatLastIndex[s[i] - 'a'], i);
    }
    string result = "";
    result += s[0];
    
    for(int i=1; i<s.length(); i++){
        if(result.find(s[i]) == string::npos){

            while (result.length() > 0) {
                char lastChar = result[result.length() - 1];
                if(lastChar > s[i] && i < alpabatLastIndex[lastChar - 'a']){
                    result = result.substr(0, result.length() - 1);
                }else{
                    break;
                }
            }
            
            result += s[i];
        }
    }

    return result;
}