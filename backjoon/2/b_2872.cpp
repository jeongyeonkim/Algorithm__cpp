// 우리집엔 도서관이 있어
// 1. 배열 뒤에부터 차례대로 큰 숫자의 책들은 뺄 필요 없음
// 2. ex ) 2 1 3 5 4 6  >> 여기서는 6, 5는 뺄 필요 없음 >> result = 4
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> books;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        int input; cin >> input;
        books.push_back(input);
    }
    int num = N;
    for(int i=N-1; i>=0; i--){
        if(num == books[i]){ num--; }
    }

    cout << num;
}