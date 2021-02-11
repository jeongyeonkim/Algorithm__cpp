// 암호 만들기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int L, C;
vector<string> arr;
vector<string> result;
int visited[16];
string checkVowel[5] = {"a", "e", "i", "o", "u"};

bool checkV(string k){
    for(int i=0; i<5; i++){
        if(k.compare(checkVowel[i]) == 0){ return true; }
    }
    return false;
}

void secret_code(int idx, int vowel, string word){
    if(word.length() == L){
        if(vowel >= 1 && L-vowel >= 2){ result.push_back(word); }
        return;
    }

    for(int i=idx; i<C; i++){
        if(visited[i] == 0){
           visited[i] = 1;
            if(checkV(arr[i])){ secret_code(i, vowel + 1, word + arr[i]); }
            else{ secret_code(i, vowel, word + arr[i]); }

            visited[i] = 0;        
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> L >> C;
    for(int i=0; i<C; i++){
        string a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    secret_code(0, 0, "");
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
}