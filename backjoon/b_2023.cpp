// 신기한 소수
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> arr;

bool check(int num){ // 소수인지 아닌지 체크
    for(int i=2; i*i<=num; i++){
        if(num % i == 0){ return false; }
    }
    return true;
}

void new_num(int num, int num_length){
    if(num_length == N){ // 길이가 N일 경우 결과에 넣기
        arr.push_back(num);
        return;
    }
    for(int i=1; i<=9; i+=2){
        if(check(num*10 + i)){
            new_num(num*10 + i, num_length + 1);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    new_num(2, 1); // 소수인 2, 3, 5, 7로 시작
    new_num(3, 1);
    new_num(5, 1);
    new_num(7, 1);
    
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << "\n";
    }
    return 0;
}   