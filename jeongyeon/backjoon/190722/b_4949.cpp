#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    while(1){
        string str;
        stack<char> check;
        bool k=true;
        getline(cin, str);
        if(str[0] == '.' && str.length() == 1)
            break;

        else{
            for(int i=0; i<str.size(); i++){
                if(str[i] == '(' || str[i] == '[')
                    check.push(str[i]);
                else if(str[i] == ')'){
                    if(check.empty() || check.top() != '('){
                        k = false;
                        break;
                    }
                    else
                        check.pop();
                }
                else if(str[i] == ']'){
                    if(check.empty() || check.top() != '['){
                        k = false;
                        break;
                    }
                    else
                        check.pop();
                }
            }
            if(check.empty() && k)
                cout << "yes" << "\n";
            else
                cout << "no" << "\n";
        }
    }
    return 0;
}