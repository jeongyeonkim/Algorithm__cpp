//  [모의 SW 역량테스트] 차량 정비소
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
int test_case, T, result, N, M, K, A, B;
int aj[10], bj[10];
int useA[10][2], useB[10][2]; // 0 = 고객 번호 , 1 = 사용시간
int useWindow[1001][2];
vector<pair <int, int> > customer; // 대기시간, 고객 번호
queue<int> waitingB;
priority_queue<int> waitingA;

bool timeout(){ // 대기 인원 없고, 모든 고객이 정비소를 한번 씩 들렸을 경우 true 반환
    if(!customer.empty()){ return false; }
    if(!waitingB.empty()){ return false; }
    if(!waitingA.empty()){ return false; }
    for(int i=1; i<=N; i++){
        if(useA[i][0] != 0){ return false; }
    }
    return true;
}

void maintain(){
    int t = 0;
    while(!timeout()){
        int s = customer.size() - 1;
        for(int i=s; i>=0; i--){ // 도착시간이 수행 시간보다 작거나 같을 경우 접수 기다리는 줄에 푸쉬
            if(t >= customer[i].first){
                waitingA.push((-1)*customer[i].second); // 우선순위 큐 -> -1 곱해서 작은 수가 최상위에 나오게
                customer.pop_back();
            }
        }

        vector<pair <int ,int> > tempWaiting; // { 이전 이용했던 창구 번호, 고객 번호 }
        for(int i=1; i<=N; i++){ // 접수 창구
            bool check = false;
            if(useA[i][0] != 0){ // 이미 누가 접수 창구에 있을 경우
                if(useA[i][1] + 1 >= aj[i]){ // 접수 창구 사용 시간이 지났을 경우
                    tempWaiting.push_back(make_pair(i, useA[i][0]));
                    check = true;
                    useA[i][0] = 0; useA[i][1] = 0;
                }
                else{ useA[i][1]++; }
            }else{ check = true; }

            if(check && !waitingA.empty()){
                useA[i][0] = (-1)*waitingA.top();
                useWindow[useA[i][0]][0] = i;
                waitingA.pop();
            }
        }

        if(!tempWaiting.empty()){ // 접수 완료된 고객들 정비 창구 대기열에 넣음
            sort(tempWaiting.begin(), tempWaiting.end()); // 접수 창구가 작은 고객 우선으로 넣음
            for(int i=0; i<tempWaiting.size(); i++){ waitingB.push(tempWaiting[i].second); }
        }

        for(int i=1; i<=M; i++){
            bool check = false;
            if(useB[i][0] != 0){
                if(useB[i][1] + 1 == bj[i]){
                    useB[i][0] = 0; useB[i][1] = 0;
                    check = true;
                }
                else{ useB[i][1]++; }
            }else{ check = true; }

            if(check && !waitingB.empty()){
                useB[i][0] = waitingB.front();
                useWindow[useB[i][0]][1] = i;
                waitingB.pop();
            }
        }
        t++;
    }
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){ return a.second > b.second; }
    return a.first > b.first;
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> M >> K >> A >> B;
        for(int i=1; i<=N; i++){ cin >> aj[i]; }
        for(int i=1; i<=M; i++){ cin >> bj[i]; }
        for(int i=1; i<=K; i++){ // { 도착 시간, 고객번호 }
            int a = 0; cin >> a;
            customer.push_back(make_pair(a, i));
        }
        sort(customer.begin(), customer.end(), cmp); // 도착 시간이 느린 순서부터 빠른 순으로 정렬 -> vector 뒤에서부터 pop 하면서 대기 고객 없애기 위해

        maintain();

        for(int i=1; i<=K; i++){ // A 접수 창구, B 정비 창구 이용한 고객 번호 더하기
            if(useWindow[i][0] == A && useWindow[i][1] == B){ result += i; }
        }
        if(result == 0){ result = -1; }
        cout << "#" << test_case << " " << result << "\n"; 
        result = 0;
        memset(aj, 0, sizeof(aj)); memset(bj, 0, sizeof(bj));
        memset(useA, 0, sizeof(useA)); memset(useB, 0, sizeof(useB));
        memset(useWindow, 0, sizeof(useWindow));
        customer.clear();
    }
    return 0;
}