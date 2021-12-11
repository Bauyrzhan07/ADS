#include<iostream>
using namespace std;
const int INF = 1000001;
int main(){
    int n,s,t;cin>>n>>s>>t;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==-1)
                a[i][j] = INF;
        }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][k]<INF&&a[k][j]<INF)
                    a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
    if(a[s-1][t-1]==INF)
        cout<<-1;
    else
        cout<<a[s-1][t-1];
    return 0;
}