#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<m;++i){
        int l=0,r=n-1,res_left=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid]==b[i]){
                res_left=mid+1;
                r=mid-1;
            }else if(a[mid]>b[i]){
                r=mid-1;
            }else{
                l=mid+1;
            }
            
        }
        if(res_left==0){
            cout<<0<<'\n';
        }else{
            l=res_left-1,r=n-1;
            int res_right=0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(a[mid]==b[i]){
                    res_right=mid+1;
                    l=mid+1;
                }else if(a[mid]>b[i]){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            cout<<res_left<<" "<<res_right<<'\n';
        }
    }    
    return 0;
}