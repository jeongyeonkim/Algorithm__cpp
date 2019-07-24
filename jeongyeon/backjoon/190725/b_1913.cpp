#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    long arr[1000][1000];
    int n=0, m=0, num=0;
    int rcheck = 0, ccheck = 0, rlimit=0, climit=0;

    cin >> n;  cin >> m;
    num = n*n;
    rlimit = n - 1;
    climit = n - 1;
    for (int r=0, c=0, k = num; k >= 1; k--) {
        if (c < climit && r == rcheck) 
            arr[c++][r] = k;
        else if (c == climit && r < rlimit) 
            arr[c][r++] = k;
        else if (c > ccheck && r == rlimit)
            arr[c--][r] = k;
        else if (c == ccheck && r > rcheck) {
            arr[c][r--] = k;
            if (r == rcheck + 1) 
                rcheck++, ccheck++, rlimit--, climit--;
        }
        else if (c == climit && c == ccheck)
            arr[c][r] = k;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << arr[i][j] << ' ';
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == m) 
                cout << i+1 << ' ' << j+1 << endl;
        }
    }
    return 0;
}