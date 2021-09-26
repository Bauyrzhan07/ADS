#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n],b[k];
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<k;++i)
        cin>>b[i];
    for(int i=0;i<k;i++){
        int l=0,r=n-1;
        bool found=false;
        while(l<=r){
            int m=l+(r-l)/2;
            if(a[m]==b[i]){
                found=true;
                break;
            }
            else if(a[m]>b[i])
                r=m-1;
            else
                l=m+1;
        }
        if(found)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}