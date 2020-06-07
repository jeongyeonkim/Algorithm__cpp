#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[100];
int a, b = 1e9;

int main(){
    cin >> N;
    cin >> M;
    int temp = 0;
    for(int i=0; i<M; i++){ cin >> arr[i]; }

    for(int i=0; i<M; i++){
        temp += arr[i];
        b = min(b, temp);
    }

    for(int i=N; i>0; i--){
        int cnt = i;
        bool check = true;
        for(int j=0; j<M; j++){
            cnt += arr[j];
            if(cnt > N){ check = false;}
        }

        if(check){ a = cnt; break;}
    }
    cout << a << "\n";
    cout << b;
    return 0;
}