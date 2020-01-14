// 문자열
#include <iostream>
#include <string>
using namespace std;
string A, B;
int result = 50;
int cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> A >> B;

    // 문자열이 더 긴 B에서 A를 비교
    for(int i=0; i<=B.length()-A.length(); i++){
           cnt=0;
           for(int j=0; j<A.length(); j++){
               if(A[j] != B[j+i]){
                   cnt++;
               }
           }
           result = min(result, cnt);
    }

    cout << result;
}