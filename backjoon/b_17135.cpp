// 캐슬 디펜스
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
int N, M, D, result;
int arr[16][16], archer[3] = {-1, -1, -1};
vector<pair <int, int> > enemy;

void killTarget(){
    vector<pair <int, int> > target;
    target = enemy;
    int cnt = 0;

    while(!target.empty()){
        int pos[target.size()]; // 죽을 타겟 인덱스 저장하는 함수
        memset(pos, 0, sizeof(pos));

        for(int i=0; i<3; i++){
            int killD = 1e9, killP = -1;
            for(int j=0; j<target.size(); j++){
                int d = abs(target[j].first - N) + abs(target[j].second - archer[i]); // 궁수 위치에서 타겟까지의 거리
                if(d <= D){ // 가장 가까운 타겟 고르기
                    if(d < killD){ killD = d; killP = j; }
                    else if (d == killD){
                        if(target[killP].second > target[j].second){ killD = d; killP = j; }
                    }
                }
            }
            if(killP != -1){ pos[killP]++; } // 여러 궁수가 한 타겟만 죽일 수도 있으므로 ++
        }

        vector<pair <int, int> > temp; // 죽거나 게임 아웃된 타겟 제외하고 남은 타겟 담을 vector
        for(int i=0; i<target.size(); i++){
            if(pos[i] >= 1){ cnt++; } // 궁수에 의해 죽는 애들
            else{
                int nx = target[i].first + 1;
                if(nx >= N){ continue; } // 체스판 밖으로 나가면 해당 타겟 게임 아웃
                temp.push_back(make_pair(nx, target[i].second));
            }
        }
        target = temp;
    }

    result = max(result, cnt);
}

void selectArcher(int n, int cnt){ // 궁수 위치 조합
    if(cnt == 3){
        killTarget();
        return;
    }

    for(int i=n; i<M; i++){
        if(archer[cnt] != -1){ continue; }
        archer[cnt] = i;
        selectArcher(i + 1, cnt + 1);
        archer[cnt] = -1;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> D;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){ enemy.push_back(make_pair(i, j)); }
        }
    }

    selectArcher(0, 0);

    cout << result;
    return 0;
}