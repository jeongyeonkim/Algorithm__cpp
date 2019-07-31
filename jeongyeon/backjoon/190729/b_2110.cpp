#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;
int c, n;
int input[MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for(int i=0; i<n; i++)
        cin >> input[i];
    sort(input, input+n);
    
    return 0;
}