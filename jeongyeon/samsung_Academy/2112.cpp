// 보호 필름
#include <iostream>
#include <algorithm>
using namespace std;
int test_case, T;
int film[14][21], temp[14][21], pill[14];
int n, m, k, result;

bool check(){
    for(int i=0; i<m; i++){
        bool check1 = false;
        for(int j=0; j<=n-k; j++){
            bool check2 = false;
            for(int z=j+1; z<j+k; z++){ // 한번에 3개 검사
                if(temp[j][i] != temp[z][i]){ check2 = true;  break; }
            }
            if(!check2){ check1 = true; break; }
        }
        if(!check1){ return false; }
    }
    return true;
}

void insertPill(int x, int cnt){
    if(cnt >= result){ return; }
    if(x == n){
        for(int i=0; i<n; i++){ // 원래 필름 복사
            for(int j=0; j<m; j++){ temp[i][j] = film[i][j]; }
        }

        for(int i=0; i<n; i++){ // 약품 넣기
            if(pill[i] == -1){ continue; }
            for(int j=0; j<m; j++){ temp[i][j] = pill[i]; }
        }

        if(check()){ result = min(cnt, result); }
        return;
    }

    pill[x] = -1;
    insertPill(x + 1, cnt);
    pill[x] = 0;
    insertPill(x + 1, cnt + 1);
    pill[x] = 1;
    insertPill(x + 1, cnt + 1);
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> n >> m >> k;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){ cin >> film[i][j]; }
        }

        result = n;
        insertPill(0, 0);
        cout << "#" << test_case << " " << result << "\n"; 
    }
    return 0;
}
