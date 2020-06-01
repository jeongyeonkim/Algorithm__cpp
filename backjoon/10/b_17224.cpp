//APC는 왜 서브태스크 대회가 되었을까? 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, K, result;
vector<int> score;

bool cmp(int a, int b){ return a > b; }

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> L >> K;
    for(int i=0; i<N; i++){
        int sub1, sub2; cin >> sub1 >> sub2;
        int sum = 0;
        if(sub1 <= L){ sum += 100; }
        if(sub2 <= L){ sum += 40; }
        score.push_back(sum);
    }

    sort(score.begin(), score.end(), cmp);
    for(int i=0; i<K; i++){
        result += score[i];
    }
    cout << result;
    return 0;
    
}