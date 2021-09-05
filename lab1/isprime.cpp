#include<iostream>
using namespace std;
bool isprime(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isprime(n))
        cout<<"prime";
    else
        cout<<"composite";
    return 0;
}