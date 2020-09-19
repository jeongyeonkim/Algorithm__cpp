#include <string>
#include <vector>
#include <stack>
using namespace std;

bool checkRight(string s){ // 올바른 괄호 문자열 체크
    stack<char> arr;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){ arr.push(s[i]); }
        else{
            if(arr.empty()){ return false; }
            else{ arr.pop(); }
        }
    }
    
    if(arr.empty()){ return true; }
    else{ return false; }
}

string solution(string p) {
    if(checkRight(p)){ return p; }
    string u = "", v = "";
    string answer = "";
    
    if(!p.compare("")){ return ""; } // 1번
    
    int left = 0, right = 0;
    for(int i=0; i<p.length(); i++){ // 2번
        if(p[i] == '('){ left++; }
        else{ right++; }
        if(left == right){
            u = p.substr(0, left*2);
            v = p.substr(left*2, p.length()-left*2);
            break;
        }
    }
    
    if(checkRight(u)){ // 3번
        answer += u;
        answer += solution(v);
    }else{ // 4번
        string t = "(" + solution(v) + ")"; // 4-1,2,3 번
        
        u = u.substr(1, u.length()-2); // 4-4 번
        string temp = "";
        for(int i=0; i<u.length(); i++){
            if(u[i] == '('){ temp += ")"; }
            else{ temp += "("; }
        }
        
        answer = t + temp; // 4-5 번
    }
    
    return answer;
}