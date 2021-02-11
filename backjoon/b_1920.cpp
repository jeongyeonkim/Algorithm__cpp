#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;
int N, input[MAX];
int M, check[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N; 
    for(int i=0; i<N; i++)
        cin >> input[i];
    cin >> M;
    sort(input, input+N);
    for(int i=0; i<M; i++){
        cin >> check[i];
        int left=0, right=N-1;
        while(left <=right){
            int mid =(left+right)/2;
            if(input[mid] == check[i]){
                cout << 1 <<"\n";
                break;
            }
            else if(input[mid] > check[i])
                right = mid-1;
            else
                left = mid+1;
        }
        if(left > right)
            cout << 0 <<"\n";
    }
    return 0;
}
