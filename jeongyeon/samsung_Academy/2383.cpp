// [모의 SW 역량테스트] 점심 식사시간
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 143
int test_case, T, n, m, s;
int room[11][11];
int match[11]; // 어떤 사람이 어떤 계단으로 갔는지
int result = 1e9;
pair<int, int> person[11], stair[2];

int dist(int idx, int idxS){ // 사람이랑 계단 거리 계산
    int dx = abs(person[idx].first - stair[idxS].first);
    int dy = abs(person[idx].second - stair[idxS].second);
    return dx+dy;
}

void lunch(){
    int sum = 0; // 모두 다 내려가는 최소 시간

    for(int i=0; i<2; i++){
        int arrival[11*2], current[MAX]; // 계단에 도착하는 사람 수, 내려가고 있는 사람 수
        memset(arrival, 0, sizeof(arrival));
        memset(current, 0, sizeof(current));
        for(int j=0; j<m; j++){
            if(match[j] == i){
                arrival[dist(j, i) + 1]++;
            }
        }

        int nowT = 0;
        for(int t=1; t<=20; t++){
            while (arrival[t] > 0){ // t시간일 때 도착한 사람이 있을 경우
                arrival[t]--;
                int remain = room[stair[i].first][stair[i].second];

                for(int wT=t; wT<MAX; wT++){
                    if(current[wT] < 3){
                        current[wT]++;
                        remain--;

                        if(remain == 0){
                            nowT = max(nowT, wT + 1);
                            break;
                        }
                    }
                }
            }
        }

        sum = max(sum, nowT);
    }
    result = min(result, sum);
}

void dfs(int cnt){
    if(cnt >= m){
        lunch();
        return;
    }

    for(int i=0; i<2; i++){
        match[cnt] = i;
        dfs(cnt+1);
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> room[i][j];
                if(room[i][j] == 1){ person[m++] = make_pair(i, j); }
                if(room[i][j] >= 2){ stair[s++] = make_pair(i, j); }
            }
        }
        dfs(0);

        cout << "#" << test_case << " " << result << "\n"; 
        m = s = 0;
        result = 1e9;
    }
    return 0;
}


// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <algorithm>
// #include <cstdlib>
// using namespace std;
// int test_case, T, result, N;
// vector<pair <int, int> > person;
// struct info{
//     int x, y, h;
// };
// vector<info> stairs;



// int main(int argc, char** argv){
//     cin>>T;
//     for(test_case = 1; test_case <= T; ++test_case){
//         cin >> N;
//         result = 1e9;
//         for(int i=1; i<=N; i++){
//             for(int j=1; j<=N; j++){
//                 int input; cin >> input;
//                 if(input == 1){ person.push_back(make_pair(i, j)); }
//                 else if(input > 1){ stairs.push_back({i, j, input}); }
//             }
//         }


//         cout << "#" << test_case << " " << result << "\n"; 
//         stairs.clear(); person.clear();
//     }
//     return 0;
// }