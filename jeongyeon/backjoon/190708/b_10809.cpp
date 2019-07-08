#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int arr[26];
    int k=0;
    string word;
    getline(cin, word);

    for(int i=0; i<26; i++)
        arr[i] = -1;

    while(word[k] != '\0'){
        if(arr[(int)word[k] - 97] == -1){
            arr[(int)word[k] - 97] = k;
            k++;
        }else
        {
            k++;
        }
    }
    for(int i=0; i<26; i++)
        cout << arr[i] << " ";
    return 0;
}