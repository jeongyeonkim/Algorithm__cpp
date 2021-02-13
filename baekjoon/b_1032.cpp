// 명령 프롬포트
#include <iostream>
#include <string.h>
using namespace std;
int N;
string arr[51];
string result;

// result 초기 값으로 첫번째 파일 명 
// 이후 파일 명의 위치 비교하면서 다르면 해당 포지션 값 '?' 으로 갱신
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }
    int len = arr[0].length();
    result = arr[0];

    for(int i=1; i<N; i++){
        for(int j=0; j<len; j++){
            if(result.at(j) != arr[i].at(j)){
                result.at(j) = '?';
            }
        }
    }

    cout << result;
}