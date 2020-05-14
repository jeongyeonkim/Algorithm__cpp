// [모의 SW 역량테스트] 특이한 자석
#include <iostream>
#include <deque>
#include <cmath>
#include <string.h>
using namespace std;
int test_case, T, result;
int K;
deque<int> arr[4];

void move(int idx, int dir, bool check[4]){
    check[idx] = true;

    if(idx > 0){ // 왼쪽
        if(arr[idx][6] != arr[idx - 1][2] && !check[idx-1]){
            move(idx - 1, dir * (-1), check);
        }
    }

    if(idx < 3){ // 오른쪽
        if(arr[idx][2] != arr[idx + 1][6] && !check[idx + 1]){
            move(idx + 1, dir * (-1), check);
        }
    }

    if(dir == 1){
        arr[idx].push_front(arr[idx].back());
        arr[idx].pop_back();
    }else{
        arr[idx].push_back(arr[idx].front());
        arr[idx].pop_front();
    }

}

int main(int argc, char** argv){
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> K;
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                int a; cin >> a;
                arr[i].push_back(a);
            }
        }

        while (K--){
            int b, c; cin >> b >> c;
            bool check[4];
            memset(check, 0, sizeof(check));
            move(b-1, c, check);
        }

        for(int i=0; i<4; i++){ // 점수 더하기
            if(arr[i][0] == 1){ result += pow(2, i); }
            arr[i].clear();
        }

        cout << "#" << test_case << " " << result << "\n"; 
        result = 0;
    }
    return 0;
}
