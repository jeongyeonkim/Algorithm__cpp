#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
map<string, vector<string> > dir;

vector<string> cutString(char ch, string str){
    vector<string> arr;
    istringstream ss(str);
    string s;
    while (getline(ss, s, ch)){
        arr.push_back(s);
    }
    return arr;
}

vector<string> solution(vector<string> directory, vector<string> command) {
    vector<string> answer;
    int idx = 0;
    answer.push_back("/");
    for(int i=0; i<directory.size(); i++){
        if(directory[i].size() > 1){
            vector<string> word = cutString('/', directory[i].substr(1, directory[i].size()-1));
            if(word.size() > 1){
                if(dir.find(word[word.size()-2]) != dir.end()){
                    dir[word[word.size()-2]].push_back(word[word.size()-1]);
                }else{
                    dir[word[word.size()-2]] = vector<string> {word[word.size()-1]};
                }
            }else{
                dir["/"].push_back = vector<string> {word[word.size()-1]};
            }
        }
    }

    for(int i=0; i<command.size(); i++){
        string com = cutString(' ', command[i])[0];
        if(com.compare("mkdir") == 0){
            string add = cutString(' ', command[i])[1].substr(1, cutString(' ', command[i])[1].size()-1);
            vector<string> word = cutString('/', add);
            if(word.size() > 1){
                dir[word[word.size()-2]].push_back(word[word.size()-1]);
            }else{
                dir["/"].push_back(word[word.size()-1]);
            }
        }
        else if(com.compare("cp")){

        }
        else if(com.compare("rm")){
            string rm = cutString(' ', command[i])[1].substr(1, cutString(' ', command[i])[1].size()-1);
            
        }
    }

    return answer;
}