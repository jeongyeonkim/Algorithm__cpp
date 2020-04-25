#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int row, col;
vector<vector<string>> arr;
vector<int> result;

bool checkMinimality(int num){ // 최소성 체크
    for(int i=0; i<result.size(); i++){
        if((result[i] & num) == result[i]){ return false; }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    arr = relation;
    row = relation.size();
    col = relation[0].size();

    for(int i=1; i<(1<<col); i++){
        set<string> key;

        for(int r=0; r<row; r++){
            string temp = "";

            for(int c=0; c<col; c++){
                if(i & (1<<c)){ temp += arr[r][c]; }
            }
            key.insert(temp);
        }

        if(key.size() == row && checkMinimality(i)){ result.push_back(i); }
    }

    answer = result.size();
    return answer;
}