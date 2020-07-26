#include <iostream>
using namespace std; 
bool odd[100];//홀수인 정점을 저장
int m, n;//정점의 수, 간선의 수
int a[100][100];//[출발 정점][도착정점]을 잊는 간선을 저장
int path[10000];//경로를 저장. 

bool EulerPath(int vertex, int idx){
     int i;
     path[idx]=vertex;//idx번째 정점을 저장. 
     
     if(idx==n){//도착지에 도달하면 출력하고 종료 
                for( i=0 ;i<n;i++){
                        cout<<path[i]+1<< "->";
                }
                cout<<path[n]+1<<endl;
                return true;
     }
     
     for(i=0;i<m;i++){
             if(a[vertex][i]>0){
                                a[vertex][i]--;//경로를 한번사용했으니
                                a[i][vertex]--; 
                                if(EulerPath(i,idx+1))return true;
                                //함수를 호출하고 참(경로 찾음)이 반환되면 참을 반환 
                                
                                a[vertex][i]++;//경로를 사용하기 전으로
                                a[i][vertex]++; 
             }
     }
     return false;//경로를 찾지 못하였다.
}
int main(){
    
    int i;
    int x,y;
    int cnt=0;//홀수 갯수 
    int lodd;//마지막 홀수 
    
    cin>>m>>n;//정점수와 간선수를 입력 받는다.
    for(i = 0; i<n;i++){
          cin>>x>>y;
          a[x-1][y-1]++;
          a[y-1][x-1]++;
          //짝수이면 홀수로 홀수이면 짝수로 
          odd[x-1]=!odd[x-1];
          odd[y-1]=!odd[y-1];
    }
    
    for(i=0;i<m;i++){
                      if(odd[i]){
                                 cnt++;
                                 lodd=i;
                      } 
    }
    
    if(cnt==0)EulerPath(0,0);//출발점이 0인 회로를 출력 
    else if(cnt==2)EulerPath(lodd,0);//출발점을 마지막 홀수차수인 정점으로 
    else cout<<"경로 없음"<<endl;//경로가 없다.
    
    return 0;
}