// 리모컨
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, input, result;
bool btn[10];

int lineNum(int num){
    int lineN = 1;
    while (num >= 10){
        lineN++;
        num /= 10;
    }
    return lineN;
}

bool ismakeit(int num){
    if(num == 0) { return btn[0]; }
    while (num){
        if(!btn[num % 10]) return false;
        num /= 10;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    memset(btn, 1, sizeof(btn));
    for(int i=0; i<M; i++){
        cin >> input;
        btn[input] = false;
    }
    result = abs(N - 100);

    int cnt = -1;
    while (++cnt <= result){
        bool flag = false;
        if(ismakeit(N + cnt)){
            result = min(result, cnt + lineNum(N + cnt));
            flag = true;
        }
        if(N - cnt >= 0 && ismakeit(N - cnt)){
            result = min(result, cnt + lineNum(N - cnt));
            flag = true;
        }

        if(flag){ break; }
    }
    
    cout << result;
    return 0;
}

// 1984KB 1196ms
// #include <iostream>
// #include <algorithm>
// #include <string.h>
// #include <vector>
// #include <cmath>
// using namespace std;
// int N, M, result = 987654321, len;
// int num[10];

// void remote(string x){
//     for(int i=0; i<10; i++){
//         if(num[i] == 0){
//             string temp = x + to_string(i);
//             // N이 10000일 경우 9999일때 1번, N이 9999일 경우 10000일때 1번으로 채널 이동이 가능하기 때문에
//             // len, len-1, len+1 다 체크해줌. 
//             if(temp.length() == len || temp.length() == len-1 || temp.length() == len+1){
//                 result = min(result, (int)(abs(N - stoi(temp)) + temp.length()));
//             }
//             if(temp.length() <= len){ remote(temp); }
//         }
//     }
// }

// int main(void){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin >> N >> M;
//     len = to_string(N).length();
//     int a = 0;
//     result = min(result,abs(100-N));

//     for(int i=0; i<M; i++){
//         cin >> a;
//         num[a]++;
//     }

//     remote("");

//     cout << result;
//     return 0;
// }