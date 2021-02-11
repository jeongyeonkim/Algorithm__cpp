#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string word, test_word;
    getline(cin,word);
    stringstream sword(word);
    int count=0;

    while(sword >> test_word){
        count++;
    }
    cout << count;

    return 0;
}