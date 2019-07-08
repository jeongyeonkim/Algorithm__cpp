#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n=0, count, c;
    cin >> n;
    double avg, percent[n];

    for(int i=0; i<n; i++){
        avg=0, count=0, c=0;
        cin >> c;
        double score[c];

        for(int j=0; j<c; j++){
            cin >> score[j];
            avg += score[j];
        }
        avg = avg/c;

        for(int j=0; j<c; j++){
            if(score[j] > avg)
                count++;
        }
        percent[i] = (float)count/c * 100;
    }
    
    cout << fixed;
    cout.precision(3);
    for(int i=0; i<n; i++){
        cout << percent[i] << "%\n";
    }
    return 0;
}