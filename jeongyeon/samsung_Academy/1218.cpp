// [S/W 문제해결 기본] 4일차 - 괄호 짝짓기
#include <iostream>
#include <stack>
using namespace std;
int test_case, T;
int result;
char Front[4] = {'(', '[', '{', '<'};
char End[4] = {')', ']', '}', '>'};
stack<char> arr;
char temp;

int main(int argc, char** argv){
    for(test_case = 1; test_case <= 10; ++test_case){
        cin >> T;
        for(int i=0; i<T; i++){
            cin >> temp;
            bool check = true;

            for(int j=0; j<4; j++){
                if(End[j] == temp && Front[j] == arr.top()){
                    arr.pop();
                    check = false;
                    break;
                }
            }

            if(check){ arr.push(temp); }
        }


        if(arr.size() == 0){ result = 1; }
        cout << "#" << test_case << " " << result << "\n"; 
        while (!arr.empty()){ arr.pop(); }
        result = 0;
    }
    return 0;
}
