// #include <iostream>
// using namespace std;
// long long fibonacci[15000001];

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     long long n=0;
//     cin >> n;
//     fibonacci[1]=1;
    
//     for(int i=2; i<=15000000; i++){
//         fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%1000000;
//     }

//     cout << fibonacci[n%15000000];
//     return 0;
// }

// 시간 초과
#include <iostream>
#include <vector>
using namespace std;

int fibo(int n);

int main()
{   
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}

int fibo(int n) {
    int answer;

    vector<int> fibo; // 배열을 만든다
    fibo.push_back(0); // 0번째는 0
    fibo.push_back(1); // 1번째는 1인 피보나치이다.

    if (n == 0) { return 0; } // fibo(0) 은 0 이라고 주어짐.
    else if (n == 1) { return 1; } // fibo(0) 은 1 이라고 주어짐.
    else {
        for (int i = 2; i <= n; i++)
        {
            fibo[2] = fibo[0] + fibo[1];
            if (fibo[2] > 1000000)
            {
                fibo[2] = fibo[2] % 1000000;
            }
            fibo[0] = fibo[1]; // 다음 연산을 위해 한 칸씩 앞으로 옮긴다
            fibo[1] = fibo[2]; // 2번 째에는 다음 연산의 값이 들어가야 하므로.
        }
        answer = fibo[2];
        return answer;
    }
}