#include <iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m=0;
    cin >> n;
    double score[n], sum;

    for(int i=0; i<n; i++){
        cin >> score[i];
        if(m < score[i])
            m = score[i];
    }

    for(int i=0; i<n; i++){
        score[i] = score[i]/m*100;
        sum += score[i];
    }

    cout << fixed;
	cout.precision(2);
    cout << sum/n;
    return 0;
}