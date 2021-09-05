#include<iostream>
using namespace std;
int euclid_algo(int a,int b){
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else if(a==b)
        return a;
    else if(a>b)
        return euclid_algo(a%b,b);
    else
        return euclid_algo(a,b%a);
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    cout<<euclid_algo(n,m);
    return 0;
}