#include<iostream>
using namespace std;
int main(){
    int n,m,res=0;
    cin>>n>>m;
    int k[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>k[i][j];
    int row_mins[n],column_max[m];
    for(int i=0;i<n;i++){
        row_mins[i]=2147483647;
        for(int j=0;j<m;j++)
            if(k[i][j]<row_mins[i])
                row_mins[i]=k[i][j];
    }
    for(int i=0;i<m;i++){
        column_max[i]=-2147483647;
        for(int j=0;j<n;j++)
            if(k[j][i]>column_max[i])
                column_max[i]=k[j][i];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(k[i][j]==column_max[j]&&k[i][j]==row_mins[i])
                res++;
    cout<<res;

    return 0;
}