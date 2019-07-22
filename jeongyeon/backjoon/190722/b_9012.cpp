#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkStack(){
    string str;
    cin >> str;
    stack<char> arr;
    for(int j=0; j<str.length(); j++){
        char ch = str[j];
        if(ch == '(')
            arr.push(ch);
        else{
            if(arr.empty())
                return 0;
            else
                arr.pop();
        }
    }
    if(arr.empty())
        return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n=0;
    cin >> n;
    string result[n];
    
    for(int i=0; i<n; i++){
        int k=0;
        k = checkStack();
        if(k == 1)
            result[i] = "YES";
        else
            result[i] = "NO";
    }
    
    for(int i=0; i<n; i++)
        cout << result[i] << "\n";
    return 0;
}