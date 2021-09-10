#include<iostream>
using namespace std;
int main(){
    int n,l,r;
    cin>>n;
    int a[n];
    int prefSum[n+1];
    prefSum[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        prefSum[i+1]=prefSum[i]+a[i];
    }
        
    return 0;
}