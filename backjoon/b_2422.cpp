// 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, result;
int visited[201], arr[201][201];
vector<int> seleted;

void dfs(int idx, int cnt){
    if(cnt == 3){ // 정답을 찾은 경우
        for(int i=0; i<seleted.size(); i++){ // 조합안되는게 있는지 체크
            for(int j=0; j<seleted.size(); j++){
                if(i == j){ continue; }
                if(arr[seleted[i]][seleted[j]]){ return; }
            }
        }
        result++;
        return;
    }

    for(int i=idx; i<=N; i++){
        if(!visited[i]){
            seleted.push_back(i);
            visited[i] = 1;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
            seleted.pop_back();
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    dfs(1, 0);
    cout << result;
}