// 스토쿠
#include <iostream>
using namespace std;
int arr[10][10];
int check_row[10][10], check_col[10][10], check[10][10];

void sdoku(){
    
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0){
                check_row[j][arr[i][j]] = 1;
                check_col[i][arr[i][j]] = 1;
                check[3*(i/3) + j/3][arr[i][j]] = 1;
            }
        }
    }
    
    sdoku();

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){ cout << arr[i][j] << " ";}
        cout << "\n";
    }
}