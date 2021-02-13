#include <iostream>
#include <string>
using namespace std;

string findWord(string str){
    string result = "";

    for(int i=0; i<str.length(); i++){
        if(str[i] == '#' && result.compare("")){
            result = result.substr(0, result.length() - 1);
        } else if(str[i] != '#'){
            
            result += str[i];
        }
    }

    return result;
}

bool backspaceCompare(string S, string T) {
    S = findWord(S);
    T = findWord(T);
    cout << S << "\n";
    cout << T << "\n";

    return (S.compare(T) == 0);
}

int main(){
    string s = "ab##";
    string t = "c#d#";
    cout << backspaceCompare(s, t);
}