#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct info{
    string _head;
    int _num;
    string _tail;
    int idx;
};

vector<info> arr;

bool cmp(const info &a, const info &b){ // head - number - 입력 순서 순으로 정렬
    if(a._head < b._head){ return true; }
    else if(a._head == b._head){
        if(a._num < b._num){ return true; }
        else if(a._num == b._num){
            if(a.idx < b.idx){ return true; }
        }
    }
    return false;
}

void split(string str, int i){
    string head, number, tail;
    bool flag = false, checkNum = false; // flag -> head 부분만 저장하기 위해 사용. checkNum -> 첫번째 나온 숫자 부분만 number로 저장하기 위해 사용.
    for(int i=0; i<str.length(); i++){
        if(!checkNum && str[i] >= '0' && str[i] <= '9'){
            flag = true;
            number += str[i];
        }else{
            if(!flag){ head += str[i]; }
            else{ tail += str[i]; checkNum = true; }
        }
    }

    arr.push_back({head, stoi(number), tail, i});
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int i=0; i<files.size(); i++){
        string temp = "";
        for(int j=0; j<files[i].length(); j++){ // 대문자 -> 소문자 변환
            if(files[i][j] >= 'A' && files[i][j] <= 'Z'){
                temp += files[i][j] - 'A' + 'a';
            }
            else{ temp += files[i][j]; }
            
        }
        split(temp, i); // head, number, tail로 나눔
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i=0; i<arr.size(); i++){
        answer.push_back(files[arr[i].idx]);
    }

    return answer;
}