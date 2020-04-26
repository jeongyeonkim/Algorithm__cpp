// [S/W 문제해결 기본] 1일차 - Flatten
#include <iostream>
#include <string.h>
using namespace std;
int test_case;
int arr[101];
int maxHight, minHight = 1000;
int maxIdx, minIdx;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(test_case = 1; test_case <= 10; ++test_case){
        int dump = 0;
        cin >> dump;

        for(int i=0; i<100; i++){
            cin >> arr[i];
            if(maxHight < arr[i]){
                maxHight = arr[i];
                maxIdx = i;
            }
            if(minHight > arr[i]){
                minHight = arr[i];
                minIdx = i;
            }
        }

        for(int i=0; i<dump; i++){
            maxHight--;
            minHight++;
            arr[maxIdx]--;
            arr[minIdx]++;

            for(int j=0; j<100; j++){
                if(maxHight < arr[j]){
                    maxHight = arr[j];
                    maxIdx = j;
                }
                if(minHight > arr[j]){
                    minHight = arr[j];
                    minIdx = j;
                }
            }
        }

        cout << "#" << test_case << " " << maxHight - minHight << "\n"; 
        memset(arr, 0, sizeof(arr));
        maxHight = maxIdx = minIdx =0;
        minHight = 1000;
    }
    return 0;
}