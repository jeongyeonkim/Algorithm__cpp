// 한 줄로 서기 

// 작은 키 부터 시작함.
// 작은 키인 사람의 자리를 한개씩 지움.
// 남은 자리에 앉을 사람 중 제일 키가 작은 사람은 i.
#include <iostream>
using namespace std;
int N, arr[11], result[11];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    // 자리 숫자를 arr에 초기화.
    for(int i=1; i<=N; i++){ arr[i] = i; }

    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        // 결과 값에 자리 번호 입력
        result[arr[a+1]] = i;
        // 이전 작은 사람이 앉은 자리 삭제하고, 남은 배열 한칸씩 옮김.
        for(int j=a+1; j<N; j++){
            arr[j] = arr[j+1];
        }
    }

    for(int i=1; i<=N; i++){
        cout << result[i] << " ";
    }
}