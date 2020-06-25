// 돌다리
#include <iostream>
#include <queue>
using namespace std;
int N, M, A, B;
long long visited[100001];
long long result;
long long arr[8];

struct info{
    long long x, cnt;
};
queue<info> que;

bool unbound(int k){
    if(k >=0 && k <= 100000){ return true; }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> A >> B >> N >> M;
    que.push({N, 0});
    for(int i=0; i<100001; i++){ visited[i] = 2e9; }

    while (!que.empty()){
        int n = que.front().x;
        int cnt = que.front().cnt;
        que.pop();

        if(n == M){
            result = cnt;
            break;
        }
        arr[0] = n + 1;
        arr[1] = n - 1;
        arr[2] = n + A;
        arr[3] = n - A;
        arr[4] = n + B;
        arr[5] = n - B;
        arr[6] = n * A;
        arr[7] = n * B;
        for(int i=0; i<8; i++){
            if(unbound(arr[i]) && cnt + 1 < visited[arr[i]]){
                que.push({arr[i], cnt + 1});
                visited[arr[i]] = cnt + 1;
            }
        }
    }
    
    cout << result;
    return 0;
}