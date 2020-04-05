// 크로아티아 알파벳
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
string str;
map<string, int> arr;
int result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    arr.insert(make_pair("c=", 1));
    arr.insert(make_pair("c-", 1));
    arr.insert(make_pair("dz=", 1));
    arr.insert(make_pair("d-", 1));
    arr.insert(make_pair("lj", 1));
    arr.insert(make_pair("nj", 1));
    arr.insert(make_pair("s=", 1));
    arr.insert(make_pair("z=", 1));
    cin >> str;

    for(int i=0; i<str.length(); i++){
        result++;
        if(str[i] == 'd' && i+2 < str.length()){
            if(arr.find(str.substr(i, 3)) != arr.end()){
                i += 2;
                continue;
            }
        }
        if(i+1 < str.length()){
            if(arr.find(str.substr(i, 2)) != arr.end()){
                i++;
                continue;
            }
        }
    }
    
    cout << result;
    return 0;
}