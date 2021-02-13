// 톱니바퀴
#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
int K, result;
deque<int> arr[5];
int score[5] = {0, 1, 2, 4, 8};

void wheels(int num, int dir, bool check[5]){
    check[num] = true;

    // 왼쪽
    if(num > 1){
        if(arr[num][6] != arr[num-1][2] && !check[num-1]){ wheels(num - 1, dir*(-1), check); }
    }
    // 오른쪽
    if(num < 4){
        if(arr[num][2] != arr[num+1][6] && !check[num+1]){ wheels(num + 1, dir*(-1), check); }
    }

    // 현재 톱니바퀴 회전
    if(dir == 1){ // 시계 방향
        arr[num].push_front(arr[num].back());
        arr[num].pop_back();
    }else{
        arr[num].push_back(arr[num].front());
        arr[num].pop_front();
    }
}

int main(void){
    for(int i=1; i<=4; i++){
        for(int j=0; j<8; j++){
            int a = 0; scanf("%1d", &a);
            arr[i].push_back(a);
        }
    }
    cin >> K;
    while(K--){
        int a = 0, b = 0;
        cin >> a >> b;
        bool check[5];
        memset(check, 0, sizeof(check));
        wheels(a, b, check);
    }

    for(int i=1; i<=4; i++){
        if(arr[i].front() == 1){ result += score[i]; }
    }

    cout << result;
    return 0;
}