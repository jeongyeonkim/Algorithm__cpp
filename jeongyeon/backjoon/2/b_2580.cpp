// 스토쿠
#include <iostream>
using namespace std;
int arr[10][10];
int check_row[10][10], check_col[10][10], check[10][10];

void sdoku(int k){
    if(k == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){ cout << arr[i][j] << " ";}
            cout << "\n";
        }
        exit(0);
    }

    int x = k/9;
    int y = k%9;

    if(arr[x][y] != 0){ sdoku(k+1); }
    else{
        for(int i=1; i<10; i++){
            if(check_row[y][i] == 0 && check_col[x][i] == 0 && check[3*(x/3) + y/3][i] == 0){
                arr[x][y] = i;
                check_col[x][i] = 1;
                check_row[y][i] = 1;
                check[3*(x/3) + y/3][i] = 1;
                
                sdoku(k + 1);

                arr[x][y] = 0;
                check_col[x][i] = 0;
                check_row[y][i] = 0;
                check[3*(x/3) + y/3][i] = 0;
            }
        }
    }
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
    
    sdoku(0);

    return 0;
}