// iSharp
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
using namespace std;
string input, allOfWord, temp;
vector<string> result;

vector<string> stringSplit(char c, string str){
    vector<string> arr;
    istringstream ss(str);
    string s;
    while (getline(ss, s, c)){
        arr.push_back(s);
    }
    return arr;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin, input);
    vector<string> arr = stringSplit(' ', input);
    allOfWord = arr[0];
    result.push_back("");

    for(int i=1; i<arr.size(); i++){
        temp = allOfWord;
        string name;
    
        for(int j=arr[i].size()-2; j>=0; j--){
            if(arr[i][j] == '*'){ temp += "*"; }
            else if(arr[i][j] == '&'){ temp += "&"; }
            else if(arr[i][j] == ']'){ temp += "[]"; }
            else if(arr[i][j] == '['){ continue; }
            else{
                temp += " ";
                temp += arr[i].substr(0, j+1);
                break;
            }
        }
        result.push_back(temp);
    }

    for(int i=1; i<result.size(); i++){ cout << result[i]  << ";\n"; }
    return 0;
}