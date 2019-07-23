#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    int n=0, k=0;
    long long num=0;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> input;
    k=n*n;
    
    while(k--){
        cin >> num;
        if(input.size() < n)
            input.push(num);
        else if(input.top() < num){
            input.pop();
            input.push(num);
        }
    }
    cout << input.top();
    return 0;
}