// 만취한 상범
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
vector<int> result;
int T, n, room[101];

void drink(){
    for(int i=2; i<=n; i++){
        for(int j=1; i*j<=n; j++){
            if(room[i*j] == 0){
                room[i*j] = -1;
            }else{
                room[i*j] = 0;
            }
        }
    }

    int cnt = 0 ;
    for(int i=1; i<=n; i++){
        if(room[i] == -1){ cnt++; }
    }
    result.push_back(cnt);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;

    for(int i=1; i<=T; i++){
        memset(room, -1, sizeof(room));
        cin >> n;
        drink();
    }


    for(int i=0; i<T; i++){
        cout << result[i] << "\n";
    }
}