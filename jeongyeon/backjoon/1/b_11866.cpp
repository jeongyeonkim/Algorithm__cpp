#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n=0, k=0;
    cin >> n >> k;
    queue<int> arr;
    for(int i=1; i<=n; i++)
        arr.push(i);
    
    cout << "<";
    while(!arr.empty()){
        for(int i=1; i<k; i++){
            arr.push(arr.front());
            arr.pop();
        }
        cout << arr.front();
        if(arr.size() != 1)
            cout << ", ";
        arr.pop();
    }
    cout << ">";
    return 0;
}