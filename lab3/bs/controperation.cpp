#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int max=-2147483647,min=2147483647;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            max=a[i];
    }
    for(int i=0;i<n;i++)
        if(a[i]==max)
            a[i]=min;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}