#include<iostream>
using namespace std;
int d[100][100],f[100][100];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            f[i][j] = 0;
        }
    
    return 0;
}