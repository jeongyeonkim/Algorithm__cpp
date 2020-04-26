#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    int n=0;
    cin >> n;
    queue<int> arr;
    for(int i=1; i<=n; i++)
        arr.push(i);
    
    while(true){
        if(arr.size() == 1){
            cout << arr.front();
            break;
        }
        else{
            arr.pop();
            arr.push(arr.front());
            arr.pop();
        }
    }
    return 0;
}