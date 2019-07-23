#include <iostream>
using namespace std;
int result[3];
int input[2190][2190];
int n;

void paper(int a, int b, int size){
    bool k=true;
    for(int i=a; i<a+size; i++){
        for(int j=b; j<b+size; j++)
            if(input[i][j] != input[a][b])
                k = false;
    }
    if(k)
        result[input[a][b]+1]++;
    else{
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++)
                paper(a+i*(size/3), b+j*(size/3), size/3);
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
    cout << result[0] << "\n" << result[1] << "\n" << result[2]; 
    return 0;
}