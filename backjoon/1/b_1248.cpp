// 맞춰봐
#include <iostream>
using namespace std;
int N;
int result[11];
bool flag = false;
char arr[11][11];

bool check(int idx){
    int sum = 0;
    for(int i=idx; i>=0; i--){
        sum += result[i];
        if(arr[i][idx] == '+' && sum <= 0){ return false; }
        else if(arr[i][idx] == '0' && sum != 0){ return false; }
        else if(arr[i][idx] == '-' && sum >= 0){ return false; }
    }
    return true;
}

void correct(int cnt){
    if(flag){ return; } // 이미 출력 된 것이 있을 경우 더이상 탐색 안함.
    if(cnt == N){
        for(int i=0; i<N; i++){
            cout << result[i] << " ";
        }
        flag = true;
        return;
    }

    for(int i=-10; i<=10; i++){ // 숫자 백트래킹으로 하나씩 다 넣어봄
        result[cnt] = i;
        if(check(cnt)){ correct(cnt + 1); }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ // 2차원 배열에 계단처럼 -, +, 0 넣음
        for(int j=i; j<N; j++){ cin >> arr[i][j]; }
    }

    correct(0);
    return 0;
}