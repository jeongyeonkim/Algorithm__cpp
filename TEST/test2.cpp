#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
char existence[3] = {'-', '*', '+'};
int sel[3];
vector<int> exist;
vector<int> idx[3];
long long answer;
vector<long long> number;

void calculation(){
    long long result;

    vector<long long> temp = number;
    for(int i=0; i<exist.size(); i++){
        for(int d=0; d<idx[sel[i]].size(); d++){
            long long before = 0, after = 0;
            int a = idx[sel[i]][d], b = idx[sel[i]][d];
            while (true){
                if(a <= 0){break;}
                a--;
                if(temp[a] != 0){ before = temp[a]; break; }
            }
            while (true){
                if(b >= temp.size()){ break; }
                b++;
                if(temp[b] != 0){ after = temp[b]; break; }
            }
            if(sel[i] == 0){ temp[a] = before - after; }
            else if(sel[i] == 1){ temp[a] = before * after; }
            else{ temp[a] = before + after; }
            temp[b] = 0;
            if(i == exist.size()-1 && d == idx[sel[i]].size()-1){ result = temp[a]; }
        }
    }
    answer = max(answer, abs(result));
}

void num(string str){
    string temp = "";
    for(int i=0; i<str.size(); i++){
        bool check = false;
        for(int e=0; e<3; e++){
            if(str[i] == existence[e]){
                check = true;
                number.push_back(stol(temp));
                idx[e].push_back(number.size());
                number.push_back(0);
                break;
            }
        }
        if(check){ temp = ""; }
        else{ temp += str[i]; }
    }
    number.push_back(stol(temp));
    for(int i=0; i<3; i++){
        if(idx[i].size() > 0){ exist.push_back(i); }
    }
}

long long solution(string expression) {
    num(expression);

    do{
        for(int i = 0; i < exist.size(); i++){
            sel[i] = exist[i];
        }
        calculation();
    }while(next_permutation(exist.begin(), exist.end()));

    return answer;
}