#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> pos;
int answer = -1, selected[300001], N;
string temp;

bool check(int num){
    for(int i=0; i<N; i++){
        if(selected[i] == num){ return true; }
    }
    return false;
}

void cntRoad(){
    int cnt = 0;
    for(int i=0; i<temp.length(); i++){
        if(temp[i] == '1' || check(i)){ cnt++; }
        else{ answer = max(answer, cnt); cnt = 0; }
    }
    answer = max(answer, cnt);
}

int solution(string road, int n) {
    temp = road;
    N = n;
    for(int i=0; i<road.length(); i++){
        if(road[i] == '0'){ pos.push_back(i); }
    }

    sort(pos.begin(), pos.end());
    do{
        for(int i = 0; i < n; i++){ selected[i] = pos[i]; }
        cntRoad();
    }while(next_permutation(pos.begin(), pos.end()));

    return answer;
}