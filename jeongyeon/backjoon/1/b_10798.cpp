#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
char input[5][CHAR_MAX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    int length_max=0;
    for(int i=0; i<5; i++){
        getline(cin, str);
        length_max = max<unsigned int>(length_max, str.size());
        for(int j=0; j<str.size(); j++)
            input[i][j] = str[j];
    }
    
    for(int i=0; i<length_max; i++){
        for(int j=0; j<5; j++){
            if(input[j][i] != NULL)
                cout << input[j][i];
        }
    }
    return 0;
}