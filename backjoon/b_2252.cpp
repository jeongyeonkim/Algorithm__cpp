// 줄세우기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, L, S;
vector<int> vec[32001];
vector<int> result;
int small[32001];
queue<int> temp;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<M; i++){
        cin >> L >> S;
        vec[L].push_back(S);
        small[S]++;
    }

    // i보다 큰게 존재하지 않을때 queue에 넣음.
    for(int i=1; i<=N; i++){
        if(small[i] == 0){ temp.push(i); }
    }

    for(int i=0; i<N; i++){
        int x = temp.front();
        result.push_back(x);
        temp.pop();

        // x보다 작은 키인 애들 중에 x를 제외하고 큰게 없을 시 queue에 넣음.
        for(int j=0; j<vec[x].size(); j++){
            small[vec[x][j]]--;
            if(small[vec[x][j]] == 0){ temp.push(vec[x][j]); }
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";   
    }
}