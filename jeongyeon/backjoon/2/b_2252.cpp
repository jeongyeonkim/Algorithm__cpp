// 줄세우기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, L, S;
vector<int> vec[32001];
vector<int> result;
int small[32001];
priority_queue<int> que;
queue<int> temp;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<M; i++){
        cin >> L >> S;
        vec[L].push_back(S);
        que.push(L);
        small[S]++;
    }

    while(!que.empty()){
        temp.push(que.top());
        que.pop();
    }

    for(int i=1; i<=N; i++){
        int x = temp.front();
        result.push_back(x);
        temp.pop();

        for(int j=0; j<vec[x].size(); j++){
            small[vec[x][j]]--;
            if(small[vec[x][j]] == 0){ temp.push(vec[x][j]); }
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";   
    }
}