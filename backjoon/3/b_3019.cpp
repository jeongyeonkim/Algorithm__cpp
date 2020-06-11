// 테트리스
#include <iostream>
using namespace std;
int C, P, result;
int arr[101];

void one(){
    result += C;
    for(int i=0; i<C-3; i++){
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2] && arr[i] == arr[i+3]){ result++; }
    }
}

void two(){
    for(int i=0; i<C-1; i++){
        if(arr[i] == arr[i+1]){ result++; }
    }
}

void three(){
    for(int i=0; i<C-2; i++){
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2] - 1){ result++; }
    }
    for(int i=0; i<C-1; i++){
        if(arr[i] == arr[i+1] + 1){ result++; }
    }
}

void four(){
    for(int i=0; i<C-2; i++){
        if(arr[i] == arr[i+1] + 1 && arr[i] == arr[i+2] + 1){ result++; }
    }
    for(int i=0; i<C-1; i++){
        if(arr[i] == arr[i+1] -1){ result++; }
    }
}

void five(){
    for(int i=0; i<C-2; i++){
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2]){ result++; }
        if(arr[i] == arr[i+1] + 1 && arr[i+1] == arr[i+2] - 1){ result++; }
    }
    for(int i=0; i<C-1; i++){
        if(arr[i] == arr[i+1] + 1){ result++; }
        if(arr[i] == arr[i+1] - 1){ result++; }
    }
}

void six(){
    for(int i=0; i<C-2; i++){
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2]){ result++; }
        if(arr[i] == arr[i+1] - 1 && arr[i+1] == arr[i+2]){ result++; }
    }
    for(int i=0; i<C-1; i++){
        if(arr[i] == arr[i+1]){ result++; }
        if(arr[i] == arr[i+1] +2){ result++; }
    }
}

void seven(){
    for(int i=0; i<C-2; i++){
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2]){ result++; }
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2] + 1){ result++; }
    }
    for(int i=0; i<C-1; i++){
        if(arr[i] == arr[i+1]){ result++; }
        if(arr[i] == arr[i+1] - 2){ result++; }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> C >> P;
    for(int i=0; i<C; i++){ cin >> arr[i]; }

    if(P == 1){ one(); }
    else if(P == 2){ two(); }
    else if(P == 3){ three(); }
    else if(P == 4){ four(); }
    else if(P == 5){ five(); }
    else if(P == 6){ six(); }
    else if(P == 7){ seven(); }

    cout << result;
    return 0;
}