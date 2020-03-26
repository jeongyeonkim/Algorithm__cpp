// 용돈 관리
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K = 10000, cashMax, low, sum;
int arr[100001];

bool manegement(int mid){
    int num = 1;
    int sum = mid;

    for(int i=0; i<N; i++){
        if(mid < arr[i]){ return false; }
        else{
            if(sum - arr[i] < 0){
                sum = mid;
                num++;
            }
        }
        sum -= arr[i];
    }
    return M >= num;
}


int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    low = 0; cashMax = sum;
    while(low <= cashMax){
        int mid = (low + cashMax)/2;

        if(manegement(mid)){
            K = mid;
            cashMax = mid - 1;
        }else{
            low = mid +1;
        }
    }

    cout << K;
    return 0;
}




// #include <algorithm>
// using namespace std;
// const int MAX = 100000;
// int N, M, cash[MAX];
// bool func(int mid){
//     int num = 1;
//     int sum = mid;
//     for (int i = 0; i < N; i++)
//     {
//         if (mid < cash[i])
//             return false;
//         if (sum - cash[i] < 0){
//             sum = mid;
//             num++;
//         }
//         sum -= cash[i];
//     }
//     return M >= num;
// }
 
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> N >> M;
//     int sum = 0;
//     for (int i = 0; i < N; i++){
//         cin >> cash[i];
//         sum += cash[i];
//     }
//     int low = 1, high = sum;
//     int result = 0;
//     while (low <= high){
//         int mid = (low + high) / 2;
            
//         if (func(mid)){
//             result = mid;
//             high = mid - 1;
//         }else
//             low = mid + 1;
//         }

//     cout << result << "\n";
//     return 0;
// }