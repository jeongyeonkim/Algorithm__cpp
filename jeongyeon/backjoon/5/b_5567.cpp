// 결혼식
#include <iostream>
#include <vector>
using namespace std;
int n, m, cnt;
vector<int> arr[501];
bool Friend[501];

// 깊이가 2 넘어가면 친구 친구 관계를 벗어나서 return
void invitation(int depth, int idx){
    if(depth > 2){ return; }
    Friend[idx] = true;

    for(int i=0; i<arr[idx].size(); i++){ invitation(depth + 1, arr[idx][i]); }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a = 0, b = 0;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    invitation(0, 1);

    for(int i=2; i<=n; i++){
        if(Friend[i]){ cnt++; }
    }
    cout << cnt;
    return 0;
}