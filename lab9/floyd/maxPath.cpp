#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
    int mx = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mx = max(mx,a[i][j]);
    cout<<mx;
    return 0;
}