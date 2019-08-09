#include <iostream>
using namespace std;
int N, cnt;
int arr[16];

bool promissing(int i){
    int k=1; 
    bool check = true;
    while(check && k < i){
        if(arr[i] == arr[k] || abs(arr[i] -arr[k]) == i-k)
            check = false;
        k++;
    }
    return check;
}

void DFS(int c){
    if(promissing(c)){
        if(c == N){
            cnt++;
            return;
        }
        for(int i=0; i<N; i++){
            arr[c+1]=i;
            DFS(c+1);
        }
    }
}

int main(){
    scanf("%d", &N);
    DFS(0);
    printf("%d", cnt);
}