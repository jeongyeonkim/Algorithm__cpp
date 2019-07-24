#include <iostream>
using namespace std;
int result[2];
int input[129][129];
int n;

void paper(int a, int b, int size){
    bool k=true;
    for(int i=a; i<a+size; i++){
        for(int j=b; j<b+size; j++)
            if(input[i][j] != input[a][b])
                k = false;
    }
    if(k)
        result[input[a][b]]++;
    else{
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++)
                paper(a+i*(size/2), b+j*(size/2), size/2);
        } 
    }
        
}
int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> input[i][j];
    }
    paper(0,0,n);
    cout << result[0] << "\n" << result[1]; 
    return 0;
}