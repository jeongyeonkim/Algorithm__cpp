#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    stack<int> arr;
    int n=0, sum=0, k=0;
    cin >> n;
    for(int i=0; i<n; i++){
        k=0;
        cin >> k;
        if(k == 0)
            arr.pop();
        else
            arr.push(k);
    }
    k = arr.size();
    for(int i=0; i<k; i++){
        sum += arr.top();
        arr.pop();
    }
    
    cout << sum;
}