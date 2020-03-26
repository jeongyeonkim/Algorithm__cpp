// 원판돌리기
#include <iostream>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;
int N, M, T, result, x, d, k;
deque<double> arr[51];
double avg, cnt;
int removePosition[51][51];

void notRemove(){
    for(int i=1; i<=N; i++){
        deque<double> temp = arr[i];
        arr[i].clear();
        for(int j=0; j<M; j++){
            if(temp[j] != -1){
                int rr = temp[j];
                if(avg > temp[j]){ rr++; }
                else if(avg < temp[j]){ rr--; }
                arr[i].push_back(rr);
            }
            else{ arr[i].push_back(-1); }
        }
    }
}

bool RemoveNum(){
    bool check = true; // 인접한 수 같은게 있으면 false, 없으면 true
    avg = 0, cnt = 0;
    memset(removePosition, 0, sizeof(removePosition)); // 삭제될 숫자 포지션 저장
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == -1){ continue; }
            avg += arr[i][j]; cnt++; // 평균 저장
            if(j != 0){
                if(arr[i][j] == arr[i][j-1]){
                    check = false;
                    removePosition[i][j] = 1;
                    removePosition[i][j-1] = 1;
                }
            }
            if(arr[i-1][j] == arr[i][j]){ // 맨 처음과 맨 끝 수 비교
                check = false;
                removePosition[i-1][j] = 1;
                removePosition[i][j] = 1;
            }
        }
        if(arr[i][0] == -1){ continue; }
        if(arr[i][0] == arr[i][arr[i].size()-1]){ // 같은 위치 이전 원판과 비교
            check = false;
            removePosition[i][0] = 1;
            removePosition[i][arr[i].size()-1] = 1;
        }
    }
    avg /= cnt;
    for(int i=1; i<=N; i++){ // 지워지는 숫자 -1로 입력
        deque<double> temp = arr[i];
        arr[i].clear();
        for(int j=0; j<M; j++){ 
            if(removePosition[i][j] == 1){ arr[i].push_back(-1); }
            else{ arr[i].push_back(temp[j]); }
        }
    }
    return check;
}

void Rotation(){
    int j = 0;
    while (true){
        j++;
        int i = j*x; // x 배수 원판 회전
        if(i > N){ break; }
        
        for(int a=0; a<k; a++){
            if(d == 0){ // 시계방향
                arr[i].push_front(arr[i].back());
                arr[i].pop_back();
            }else{ // 반시계 방향
                arr[i].push_back(arr[i].front());
                arr[i].pop_front();
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            arr[0].push_back(-1);
            int a = 0; cin >> a;
            arr[i].push_back(a);
        }
    }

    while (T--){
        cin >> x >> d >> k;
        Rotation(); // 회전
        if(RemoveNum()){ // 인접한 수 있는지 확인
            notRemove(); // 인접한 수 없을 경우 평균 대소 비교
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] != -1){ result += (int)arr[i][j]; }
        }
    }

    cout << result << "\n";
    return 0;
}