// 로직 다시 짜기
// 테케 16, 30 틀림

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

bool checkSong(string shortSong, string longSong){
    int pos = longSong.find(shortSong);
    int idx = pos + shortSong.length();
    int shortIdx = 0;
    bool res = true;
    while (true){
        if(idx == pos){ break; }
        if(longSong[idx] != shortSong[shortIdx]){
            res = false;
            break;
        }
        idx++; shortIdx++;
        idx %= longSong.length();
        shortIdx %= shortSong.length();
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    m = changeString(m);
    
    for(int i=0; i<musicinfos.size(); i++){
        vector<string> song = split(musicinfos[i], ',');
        bool check = false;
        song[3] = changeString(song[3]);
        song_time = playSongTime(song[0], song[1]);

        if(song[3].length() == m.length()){ // 서로 같은 길이일 경우, 어느 부분부터 시작한지를 모르니까 m의 첫 시작점부터 같은게 있는지 다 비교
            int idx = 0;
            while (true){
                if(check || idx >= m.length()){ break; }
                if(song[3].find(m[0], idx) != string::npos){
                    int startPos = song[3].find(m[0], idx);

                    if(m.substr(0, m.length() - startPos).compare(song[3].substr(startPos, m.length() - startPos)) == 0){
                        if(m.substr(m.length() - startPos, startPos).compare(song[3].substr(0, startPos)) == 0){
                            check = true;
                        }
                    }
                }
                idx++;
            }
        }
        else if(song[3].length() < m.length()){
            if(checkSong(song[3], m)){ check = true; }
        }
        else{
            string tempSong = song[3];
            tempSong += song[3].substr(0, m.length());
            if(tempSong.find(m) != string::npos){ check = true; }
        }

        if(check){ // 같은 노래일때
            if(song_time > res_song_time){ // 재생 시간이 이전 곡보다 더 길 경우
                res_song_time = song_time;
                res_song_name = song[2];
            }
        }
    }

    return res_song_name;
}