#include <iostream>
using namespace std;
int arr1[100][100];
int arr2[100][100];
int result[100][100];

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int a=0, b=0, c=0;
    cin >> a >> b;
    for(int i=0; i<a; i++)
        for(int j=0; j<b; j++)
            cin >> arr1[i][j];
    
    cin >> b >> c;
    for(int i=0; i<b; i++)
        for(int j=0; j<c; j++)
            cin >> arr2[i][j];
    
    for(int i=0; i<a; i++)
        for(int j=0; j<c; j++)
            for(int k=0; k<b; k++)
                result[i][j] += (arr1[i][k]*arr2[k][j]);
    
    for(int i=0; i<a; i++){
        for(int j=0; j<c; j++)
            cout << result[i][j] <<" ";
        cout << "\n";
    }
    return 0;
}