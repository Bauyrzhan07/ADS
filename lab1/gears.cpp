#include<iostream>
using namespace std;
long long euclid_algo(long long a,long long b){
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
long long nok(long long a,long long b){
    return (a*b)/euclid_algo(a,b);
}
int main(){
    long long n,m;
    cin>>n>>m;
    cout<<nok(n,m);
    return 0;
}