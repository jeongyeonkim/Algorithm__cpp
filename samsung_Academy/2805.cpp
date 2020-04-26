#include <iostream>
#include <ios>
using namespace std;
int arr[50][50], N;

int FARM(){
    int result = 0;
    for(int i=0; i< N/2; i++){
        for(int j = N/2 -i; j <= N/2 +i; j++){
            result += arr[i][j];        
        }
    }   
    for(int i = N/2; i >= 0; i--){
       for(int j = (N/2)-i; j <= (N/2)+i; j++){
           result += arr[N -1 -i][j]; 
        }
    }
    return result;
}

int main(int argc, char** argv){
    int T; cin >> T;

    for(int t=1; t<=T; t++){
        cin >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%1d", &arr[i][j]);
            }
        }
        cout << "#" << t << " " << FARM() << "\n";
    }
    return 0;
}
    