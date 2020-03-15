// 거의 최단 경로
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;
int N, M, S, D, U, V, P;
int firstRoot = MAX, secondRoot = MAX;
bool visited[501];
vector<pair <int, int> > arr[501], removeRoot;

void secondShortRoot(int idx, int sum){
    if(idx == D){ secondRoot = min(secondRoot, sum); return; }

    for(int i=0; i<arr[idx].size(); i++){
        if(!visited[arr[idx][i].first]){
            visited[arr[idx][i].first] = true;
            secondShortRoot(arr[idx][i].first, sum + arr[idx][i].second);
        }
    }
}

void shortRoot(int idx, int sum, vector<pair <int, int> > vec){
    if(idx == D){
        if(firstRoot > sum){
            firstRoot = sum;
            removeRoot = vec;
        }
        return;
    }

    for(int i=0; i<arr[idx].size(); i++){
        if(!visited[arr[idx][i].first]){
            visited[arr[idx][i].first] = true;
            vec.push_back(make_pair(idx, arr[idx][i].first));
            shortRoot(arr[idx][i].first, sum + arr[idx][i].second, vec);
            vec.pop_back();
            visited[arr[idx][i].first] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (true){
        cin >> N >> M;
        if(!N && !M){ return 0; }
        cin >> S >> D;
        for(int i=0; i<M; i++){
            cin >> U >> V >> P;
            arr[U].push_back(make_pair(V, P));
        }
        
        vector<pair <int, int> > temp;
        shortRoot(S, 0, temp);
        for(int i=0; i<removeRoot.size(); i++){
            for(int j=0; j<arr[removeRoot[i].first].size(); j++){
                if(arr[removeRoot[i].first][j].first == removeRoot[i].second){
                    arr[removeRoot[i].first].erase(arr[removeRoot[i].first].begin() + j);
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        secondShortRoot(S, 0);
        
        if(secondRoot == MAX){ secondRoot = -1; }
        cout << secondRoot << "\n";
        memset(visited, 0, sizeof(visited));
        firstRoot = secondRoot = MAX;
        removeRoot.clear();
        for(int i=0; i<N; i++){ arr[i].clear(); }
    }
    return 0;
}




// 시간초과 
// #include <iostream>
// #include <string.h>
// #include <vector>
// #include <algorithm>
// #define MAX 987654321
// using namespace std;
// int N, M, S, D, U, V, P;
// int firstRoot = MAX, secondRoot = MAX;
// bool visited[501];
// vector<pair <int, int> > arr[501], removeRoot;

// void secondShortRoot(int idx, int sum){
//     if(idx == D){ secondRoot = min(secondRoot, sum); return; }

//     for(int i=0; i<arr[idx].size(); i++){
//         if(!visited[arr[idx][i].first]){
//             visited[arr[idx][i].first] = true;
//             secondShortRoot(arr[idx][i].first, sum + arr[idx][i].second);
//         }
//     }
// }

// void shortRoot(int idx, int sum, vector<pair <int, int> > vec){
//     if(idx == D){
//         if(firstRoot > sum){
//             firstRoot = sum;
//             removeRoot = vec;
//         }
//         return;
//     }

//     for(int i=0; i<arr[idx].size(); i++){
//         if(!visited[arr[idx][i].first]){
//             visited[arr[idx][i].first] = true;
//             vec.push_back(make_pair(idx, arr[idx][i].first));
//             shortRoot(arr[idx][i].first, sum + arr[idx][i].second, vec);
//             vec.pop_back();
//             visited[arr[idx][i].first] = false;
//         }
//     }
// }

// int main(void){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     while (true){
//         cin >> N >> M;
//         if(!N && !M){ return 0; }
//         cin >> S >> D;
//         for(int i=0; i<M; i++){
//             cin >> U >> V >> P;
//             arr[U].push_back(make_pair(V, P));
//         }
        
//         vector<pair <int, int> > temp;
//         shortRoot(S, 0, temp);
//         for(int i=0; i<removeRoot.size(); i++){
//             for(int j=0; j<arr[removeRoot[i].first].size(); j++){
//                 if(arr[removeRoot[i].first][j].first == removeRoot[i].second){
//                     arr[removeRoot[i].first].erase(arr[removeRoot[i].first].begin() + j);
//                 }
//             }
//         }

//         memset(visited, 0, sizeof(visited));
//         secondShortRoot(S, 0);
        
//         if(secondRoot == MAX){ secondRoot = -1; }
//         cout << secondRoot << "\n";
//         memset(visited, 0, sizeof(visited));
//         firstRoot = secondRoot = MAX;
//         removeRoot.clear();
//         for(int i=0; i<N; i++){ arr[i].clear(); }
//     }
//     return 0;
// }