#include<iostream>
using namespace std;
int main(){
    int n,max=-2147483647;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        if(a[i]>=max)
            max=a[i];
    cout<<max;
    return 0;
}