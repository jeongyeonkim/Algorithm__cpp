#include <iostream>
#define MAX 20000002
using namespace std;
int N, input[MAX];
int M, check[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N; 
    for(int i=0; i<N; i++){
        int K=0; cin >> K;
        if(K<0)
            input[K*(-1)+10000000]++;
        else
            input[K]++;
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int K=0; cin >> K;
        if(K<0)
            check[i] = input[K*(-1)+10000000];
        else
            check[i] = input[K];
    }
    
    for(int i=0; i<M; i++)
        cout << check[i] << " ";
    
    return 0;
}