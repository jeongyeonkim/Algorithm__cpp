#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL);
    int n=0, k=0, result=1;
    cin >> n >> k;
    
    for(int i=0; i<k; i++){
        result *= n-i;
        result /= (i+1);
    }
    cout << result;
    return 0;
}