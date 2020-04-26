#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> arr; // 문자열을 key값으로 찾아야 해서 map 사용

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i=1; i<=26; i++){ // A ~ Z 까지 저장
        string  str;
        str = i + 64; 
        arr.insert(make_pair(str, i));
    }
    
    for(int i=0; i<msg.length(); i++){
        int num = 0;
        for(int j=msg.length(); j>i; j--){ // 맨 끝자리부터 점점 문자열 길이 줄여가면서 find
            if(arr.find(msg.substr(i, j-i)) != arr.end()){
                answer.push_back(arr.find(msg.substr(i, j-i))->second);
                num = j;
                break;
            }
        }
        arr.insert(make_pair(msg.substr(i, num-i+1), arr.size()+1)); // 등록되어 있는 최대 길이 문자열 다음 문자 까지 새로 사전에 등록
        i += num-i-1;
    }
                             
    return answer;
}