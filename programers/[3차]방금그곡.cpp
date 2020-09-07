/*
    1. split을 사용하여 시작 시간, 종료 시간, 노래 제목, 멜로디로 나누기
    2. find 함수를 쓰기 위해 모든 #붙여진 멜로디 환산하기 (changeString함수)
    3. 재생 시간 구한 후 멜로디 재생 시간 길이로 만든 후 m이 포함되어 있는지 아닌지 여부 판단
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string res_song_name = "(None)";
int res_song_time, song_time;

vector<string> split(string input, char ch){ // split 함수
    vector<string> temp;
    istringstream ss(input);
    string s;

    while (getline(ss, s, ch)) { temp.push_back(s); }
    return temp;
}

int playSongTime(string start, string end){ // 재생 시간 계산하는 함수
    int startH = atoi(start.substr(0, 2).c_str()) * 60 + atoi(start.substr(3, 2).c_str());
    int endH = atoi(end.substr(0, 2).c_str()) * 60 + atoi(end.substr(3, 2).c_str());

    return endH - startH;
}

string changeString(string str){ // #붙은거 단위 환산 ex) C# -> c
    string tmp = "";
    for(int i=0; i<str.length(); i++){
        if(str[i] == '#'){
            char ch = tmp[tmp.length()-1] - 'A' + 'a';
            tmp = tmp.substr(0, tmp.length() -1);
            tmp += ch;
        }
        else{ tmp += str[i]; }
    }
    return tmp;
}

string solution(string m, vector<string> musicinfos) {
    m = changeString(m);
    
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> song = split(musicinfos[i], ',');
        bool check = false;
        song[3] = changeString(song[3]);
        song_time = playSongTime(song[0], song[1]);

        if(res_song_time < song_time){
            string temp = "";
            for(int j=0; j<song_time; j++){
                temp += song[3][j % song[3].length()];
            }

            if(temp.find(m) >= 0 && temp.find(m) < temp.length()){
                res_song_time = song_time;
                res_song_name = song[2];
            }
        }
    }

    return res_song_name;
}