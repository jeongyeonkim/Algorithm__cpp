// 가르침
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, result;
vector<int> inputWord;
int alphabetLearn;

// 1. 알파벳 사용 유무 > 비트마스킹 사용
// 2. a, n, t, i, c는 항상 쓰이는 단어로 alphabetLearn에 미리 넣어놓기
// 3. 알파벳 조합 + 백트래킹 사용
void learnWord(int startIndex, int cntAlphabet){
    if(cntAlphabet == K){
        int cntWord = 0;
        for(int i=0; i<inputWord.size(); i++){
            if(inputWord[i] == (alphabetLearn & inputWord[i])){ cntWord++; }
        }

        result = max(result, cntWord);
        return;
    }

    for(int i=startIndex; i<26; i++){
        if(!(alphabetLearn & (1 << i))){
            alphabetLearn |= (1 << i);
            learnWord(i + 1, cntAlphabet + 1);
            alphabetLearn &= ~(1 << i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++){
        string input;
        int word = 0;
        cin >> input;
        for(int j=4; j<(int)input.length() - 4; j++){
            word |= (1 << (input[j] - 'a'));
        }
        inputWord.push_back(word);
    }

    if(K < 5){
        cout << 0;
    } else if(K == 26){
        cout << N;
    } else{
        alphabetLearn |= (1 << ('a' - 'a'));
        alphabetLearn |= (1 << ('n' - 'a'));
        alphabetLearn |= (1 << ('t' - 'a'));
        alphabetLearn |= (1 << ('i' - 'a'));
        alphabetLearn |= (1 << ('c' - 'a'));

        learnWord(0, 5);
        cout << result;
    }

    return 0;
}