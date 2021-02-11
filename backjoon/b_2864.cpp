// 5와 6의 차이
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
string str1, str2;
vector<int> num;

void cal(string temp){
    for(int i=0; i<temp.length(); i++){
        if(temp[i] == '5'){ num.push_back(pow(10, temp.length()-i-1)); }
        else if(temp[i] == '6'){ num.push_back((-1)*pow(10, temp.length()-i-1)); }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str1 >> str2;

    cal(str1);
    cal(str2);
    
    int plusNum = 0, minusNum = 0;
    for(int i=0; i<num.size(); i++){
        if(num[i] > 0){ plusNum += num[i]; }
        else{ minusNum += num[i]; }
    }
    cout << stoi(str1) + stoi(str2) + minusNum << " " << stoi(str1) + stoi(str2) + plusNum;
    return 0;
}