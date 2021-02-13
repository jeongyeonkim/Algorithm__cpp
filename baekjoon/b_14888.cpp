#include <iostream>
#include <algorithm>
using namespace std;
int N, MAX=-1000000001, MIN=1000000001;
int Operator[4];
int arr[12];

void DFS(int plus, int minus, int multiply, int divide, int cnt, int result){
    if(cnt == N){
        MAX = max(MAX, result);
        MIN = min(MIN, result);
    }
    else{
        if(plus > 0)
            DFS(plus-1, minus, multiply, divide, cnt + 1, result + arr[cnt]);
        if(minus > 0)
            DFS(plus, minus-1, multiply, divide, cnt + 1, result - arr[cnt]);
        if(multiply > 0)
            DFS(plus, minus, multiply-1, divide, cnt + 1, result * arr[cnt]);
        if(divide > 0)
            DFS(plus, minus, multiply, divide-1, cnt + 1, result / arr[cnt]);
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<4; i++)
        scanf("%d", &Operator[i]);
    
    DFS(Operator[0], Operator[1], Operator[2], Operator[3], 1, arr[0]);
    printf("%d \n", MAX);
    printf("%d", MIN);
}