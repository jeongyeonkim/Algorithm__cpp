// [모의 SW 역량테스트] 미생물 격리
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int test_case, T, result;
int N, M, K;
int dx[4] = {0, 1, 0, -1}; // 동, 남, 서, 북
int dy[4] = {1, 0, -1, 0};

struct info{
    int x, y, micro, dir;
    bool active; // 미생물 수가 0 이거나 다른 미생물과 합쳐질 경우 죽은애, 안 죽은애로 나눔
    int beforeMicro; // 이전 미생물 수랑 비교하기 위해서 저장 (합계 미생물 수랑은 다른거)
};
vector<info> arr;

void isolation(){
    while (M--){
        int map[101][101];
        memset(map, -1, sizeof(map));
        for(int i=0; i<arr.size(); i++){
            if(!arr[i].active){ continue; } // 이미 죽은 애면 continue
            int x = arr[i].x, y = arr[i].y;
            int micro = arr[i].micro, dir = arr[i].dir, beforeMicro = arr[i].beforeMicro;
            int check = true;

            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx == 0 || ny == 0 || nx == N-1 || ny == N-1){ //약품에 닿았을 때
                if(micro >= 2){ micro /= 2; } // 2 이상이면 반으로 나눔
                else{ micro = 0; } // 2보다 작으면 0
                dir = (dir + 2) % 4; // 반대 방향으로 바꿈
                if(micro == 0){ check = false; }
            }else{
                if(map[nx][ny] != -1){ // 다른 미생물과 합쳐질 경우
                    check = false;
                    int idx = map[nx][ny];
                    if(micro > arr[idx].beforeMicro){ // 미생물 수 가 더 많은 애의 방향으로 바꿈
                        arr[idx].dir = dir;
                        arr[idx].beforeMicro = micro;
                    }
                    arr[idx].micro += micro; // 현재 미생물은 비활성화 시키고, 이전 미생물에 미생물 수 더함
                }
            }

            if(check){
                map[nx][ny] = i;
                arr[i].beforeMicro = micro;
            }
            arr[i].x = nx; arr[i].y = ny;
            arr[i].micro = micro; arr[i].dir = dir;
            arr[i].active = check;
        }
    }
}

int main(int argc, char** argv){
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> M >> K;
        for(int i=0; i<K; i++){
            int a, b, c, d; cin >> a >> b >> c >> d;
            if(d == 1){ d = 3;}
            else if(d == 2){ d = 1; }
            else if(d == 3){ d = 2; }
            else{ d = 0; }
            arr.push_back({a, b, c, d, true, -1}); // 미생물 정보 arr에 저장
        }

        isolation();

        for(int i=0; i<arr.size(); i++){
            if(!arr[i].active){ continue; }
            result += arr[i].micro;
        }

        cout << "#" << test_case << " " << result << "\n"; 
        arr.clear();
        N = M = K = 0;
        result = 0;
    }
    return 0;
}
