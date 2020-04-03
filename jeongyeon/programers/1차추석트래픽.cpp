// 테케 1개 안맞음
// ["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"] -> 2
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> cutString(char ch, string str){
    vector<string> arr;
    istringstream ss(str);
    string s;
    while (getline(ss, s, ch)){
        arr.push_back(s);
    }
    return arr;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<string> str;
    vector<int> startT, endT;

    int endTime = 0, startTime = 0;

    for(int i=0; i<lines.size(); i++){
        str = cutString(' ', lines[i]);
        
        endTime = stoi(cutString(':', str[1])[0]) * 3600000 + stoi(cutString(':', str[1])[1]) * 60000 + stod(cutString(':', str[1])[2]) * 1000;
        string temp = str[2].substr(0, str[2].length()-1);
        startTime = endTime - stod(temp) * 1000; startTime--;

        endT.push_back(endTime);
        startT.push_back(startTime);
    }

    for(int i=0; i<lines.size(); i++){
        int cnt = 0;
        int endPoint = startT[i] + 999;

        for(int j=0; j<lines.size(); j++){
            if(endT[j] >= startT[i] && startT[j] <= endPoint){ cnt++; }
            else if(startT[j] <= endPoint && startT[j] >= startT[i]){ cnt++; }
        }
        answer = max(answer, cnt);
    }

    return answer;
}