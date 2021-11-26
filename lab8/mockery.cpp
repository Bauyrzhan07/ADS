#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>d[i][j];
    int mx = 1e9;
    vector<int> ans;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            if(a==b)
                continue;
            for(int c=0;c<n;c++){
                if(c==a||c==b)
                    continue;
                if(d[a][b]+d[b][c]+d[c][a]<mx){
                    mx = d[a][b]+d[b][c]+d[c][a];
                    ans = {a,b,c};
                }
            }
        }
    }
    for(int i:ans)
        cout<<i+1<<" ";
    return 0;
}