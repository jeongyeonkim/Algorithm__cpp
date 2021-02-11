//보물
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, num, result;
vector<int> A, B;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        A.push_back(num);
    }
    for(int i=0; i<N; i++){
        cin >> num;
        B.push_back(num);
    }

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end());

    for(int i=0; i<N; i++){
        result += (A[i] * B[i]);
    }

    cout << result;
    return 0;
}