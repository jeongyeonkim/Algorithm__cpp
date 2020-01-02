#include<iostream>
#include <algorithm>
using namespace std;
int sum[36];

bool asc(int a, int b){ return a > b; }

int result(){
    int cnt = 0, beforNum=0;
    for(int i=0; cnt<5; i++){
        if(beforNum != sum[i]){
            cnt++;
            beforNum = sum[i];
        }
    }

    return beforNum;
}
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int arr[8];
        for(int i=0; i<7; i++)
            cin >> arr[i];
        int cnt=0;
        for(int i=0; i<5; i++){
            for(int j=i+1; j<6; j++){
                for(int k=j+1; k<7; k++){
                    sum[cnt] = arr[i] + arr[j] + arr[k];
                    cnt++;
                }
            }
        }
        sort(sum, sum+35, asc);

        cout << "#" << test_case << " " << result() << "\n";
	}
	return 0;
}