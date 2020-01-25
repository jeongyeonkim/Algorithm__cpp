#include <iostream>
#include <vector>
using namespace std;
int N, result[1001], output;
vector<int> arr;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        int a=0; cin >> a;
        arr.push_back(a);
    }
    result[0]=1;
    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[i] < arr[j]){
                result[i] = max(result[i], result[j]);
            }
        }
        result[i]++;
    }
    
    for(int i=0; i<N; i++){
        output = max(output, result[i]);
    }
    cout << output;
}