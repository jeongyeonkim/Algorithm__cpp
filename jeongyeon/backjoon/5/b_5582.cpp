// 공통 부분 문자열
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string arr1, arr2;
int common[4001][4001], result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> arr1 >> arr2;

    arr1 = '/' + arr1;
    arr2 = '/' + arr2;

    for(int i=0; i<arr1.length(); i++){
        for(int j=0; j<arr2.length(); j++){
            if(arr1.at(i) == arr2.at(j)){
                if(i == 0 || j == 0){ continue; }

                common[i][j] = common[i-1][j-1] + 1;
                result = max(result, common[i][j]);
            }
        }
    }
    cout << result;
}