// 통나무 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, K, C, result1, result2;
vector<int> location;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> L >> K >> C;
    location.push_back(0);
    for(int i=1; i<=K; i++){ cin >> location[i]; }
    location.push_back(L);

    sort(location.begin(), location.end());


}

// #include <iostream>
// #include <vector>
// #include <math.h>
// using namespace std;
// /*
// <입력>
// 통나무길이, 자를 수 있는 위치 수, 최대 자를 수 있는 수
// */


// int main()
// {
//    int l, k, c;
   
//    cin >> l >> k >> c;

//    vector<int> cutting;
//    // 자르는 위치들을 넣을 배열을 하나 만들자고.

//    for (int i = 0; i < k; i++)
//    {
//       int put;
//       cin >> put;
//       cutting.push_back(put);
//    }
//    // 자를 수 있는 횟수만큼 자르는 위치가 주어질테니 차례로 넣고

//    int start = 0;
//    int end = k;
   
//    // 자르는 첫 위치와 끝 위치를 설정하자고.
//    // 잘라서 차이가 가장 적게 나는 거 중 긴 쪽에서 첫과 끝을 잡으면 끝이잖아
//    int trial = 0;
//    vector<int> firstone;

//    int min = 1000000;
//    int longer = 0;
//    int change = 0;
//    while (trial <= c)
//    {
//       int point;
//       int changed = 0;
//       for (int i = start; i <= end; i++)
//       {
//          if (abs((cutting[i] - start) - (end - cutting[i])) < min)
//          {
//             changed++;
//             min = abs((cutting[i] - start) - (end - cutting[i]));
//             if (cutting[i] - start > end - cutting[i])
//             {
//                longer = cutting[i] - start;
//                end = i;
//                firstone.push_back(i);
//             }
//             else {
//                longer = end - cutting[i];
//                start = i;
//                firstone.push_back(i);
//             }
//          }
//       }
//       if (changed == 0)
//       {
//          break;
//       }
//       trial++;
//       change++;
//    }

//    cout << longer << firstone[0]<< endl;

//    return 0;
// }