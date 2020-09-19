#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
bool answer;
int keySize, total_hole;
int keys[21][21];
vector<vector<int>> locks;

void open_the_door(int x, int y){
    int cnt_hole = 0;

    for(int i=x; i<locks.size(); i++){
        if(i-x >= keySize){ continue; }
        for(int j=y; j<locks.size(); j++){
            if(j-y >= keySize){ continue; }
            if(keys[i-x][j-y]){
                if(locks[i][j] == 0){ cnt_hole++; }
                else{ return; }
            }
            else if(locks[i][j] == 0){ return; }
        }
    }

    if(cnt_hole == total_hole){ answer = true; }
}

void open_the_door2(int x, int y){
    int cnt_hole = 0;

    for(int i=0; i<locks.size(); i++){
        if(i+x >= keySize){ continue; }
        for(int j=0; j<locks.size(); j++){
            if(j+y >= keySize){ continue; 
            if(keys[i+x][j+y]){
                if(locks[i][j] == 0){ cnt_hole++; }
                else{ return; }
            }
            else if(locks[i][j] == 0){ return; }
        }
    }

    if(cnt_hole == total_hole){ answer = true; }
}

void rotationKEY(){
    int tmpKey[21][21];
    memset(tmpKey, 0, sizeof(tmpKey));

    for(int i=0; i<keySize; i++){
        for(int j=0; j<keySize; j++){ tmpKey[i][j] = keys[j][keySize - i - 1]; }
    }
    for(int i=0; i<keySize; i++){
        for(int j=0; j<keySize; j++){ keys[i][j] = tmpKey[i][j]; }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    keySize = key.size();
    locks = lock;

    for(int i=0; i<keySize; i++){
        for(int j=0; j<keySize; j++){ keys[i][j] = key[i][j]; }
    }
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            if(lock[i][j] == 0){ total_hole++; }
        }
    }

    for(int t=0; t<4; t++){
        for(int i=0; i<lock.size(); i++){
            for(int j=0; j<lock.size(); j++){
                open_the_door(i, j);
                if(answer){ break; }
            }

            if(answer){ break; }
        }
        if(answer){ break; }

        for(int i=0; i<keySize; i++){
            for(int j=0; j<keySize; j++){
                open_the_door2(i, j);
                if(answer){ break; }
            }

            if(answer){ break; }
        }
        if(answer){ break; }

        rotationKEY();
    }
    
    return answer;
}