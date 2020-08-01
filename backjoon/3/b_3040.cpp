// 백설 공주와 일곱 난쟁이
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int input, sum;
int idx1, idx2;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0; i<9; i++){
        cin >> input;
        arr.push_back(input);
        sum += input;
    }
    bool flag = false;
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum - arr[i] - arr[j] == 100){
                flag = true;
                idx1 = i;
                idx2 = j;
                break;
            }
        }
        if(flag){ break; }
    }

    for(int i=0; i<9; i++){
        if(i == idx1 || i == idx2){ continue; }
        cout << arr[i] << "\n";
    }
    return 0;
}

