#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,q,w;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>q>>w;
    int old_val = a[q-1],new_val = a[w-1];
    for(int i=0;i<n;i++)
        if(a[i]==old_val)
            a[i] = new_val;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}