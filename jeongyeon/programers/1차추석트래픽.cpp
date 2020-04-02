#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> cut(string str, char k){
    vector<string> arr;
    istringstream ss(str);
    string s;

    while (getline(ss, s, k)){
        arr.push_back(s);
    }
    
    return arr;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> startT;
    vector<int> endT;

    vector<string> temp;
    for(int i=0; i<lines.size(); i++){
        temp = cut(lines[i], ' ');
        vector<string> sec = cut(cut(temp[2], ':')[2], '.');
        string s = sec[0] + sec[1];

        int endTime = stoi(cut(temp[1], ':')[0]) * 3600000 + stoi(cut(temp[1], ':')[1]) * 60000 + stof(cut(temp[1], ':')[2]) * 1000;
        endT.push_back(endTime);
        int startTime = endTime - stof(sec[0] + sec[1])*1000 -1;
        startT.push_back(startTime);
    }

    for(int i=0; i<lines.size(); i++){
        int cnt = 0;
        int startTime = startT[i] - 1000;

        for(int j=0; j<lines.size(); j++){
            if(startTime <= startT[j] && startT[i] >= startT[j]){
                cnt++;
            }else if(startTime >= startT[j] && endT[j] >= startTime){
                cnt++;
            }
        }

        answer = max(answer, cnt);
    }
    return answer;
}