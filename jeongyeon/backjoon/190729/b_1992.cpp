#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int input[64][64];
int n;
vector<char> result;

void QuadTree(int a, int b, int size){
    bool k=true;
    for(int i=a; i<a+size; i++){
        for(int j=b; j<b+size; j++)
            if(input[i][j] != input[a][b])
                k = false;
    }
    if(k){
        if(input[a][b] == 1)
            result.push_back('1');
        else
            result.push_back('0');
    }
    else{
        result.push_back('(');
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                QuadTree(a+i*(size/2), b+j*(size/2), size/2);
            }
        }
        result.push_back(')');
    }
}
int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        string str; cin >> str;
        for(int j=0; j<n; j++){
            input[i][j]=stoi(str.substr(j,1));
        }
    }
    QuadTree(0,0,n);
    for(int i=0; i<result.size(); i++)
        cout << result[i];
    return 0;
}