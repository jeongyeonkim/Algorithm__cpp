// 회전하는 큐
#include <iostream>
#include <deque>
using namespace std;
int N, M, cnt;
deque<int> dq;

int findIndex(int num){
    for(int i=0; i<dq.size(); i++){
        if(dq[i] == num){
            return i;
        }
    }
    return 0;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){ dq.push_back(i); }

    for(int i=0; i<M; i++){
        int k=0;
        cin >> k;
        int idx = findIndex(k);

        if(idx < dq.size()-idx){
            for(int j=0; j<dq.size(); j++){
                if(k == dq.front()){
                    dq.pop_front();
                    break;
                }
                ++cnt;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            for(int j=0; j<dq.size(); j++){
                if(k == dq.front()){
                    dq.pop_front();
                    break;
                }
                ++cnt;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << cnt;
}