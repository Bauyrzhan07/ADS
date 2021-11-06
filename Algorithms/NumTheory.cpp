#include<bits/stdc++.h>
using namespace std;
int euler(int n){
    int res=n;
    for(int i=2;i<=n/i;i++)
        if(n%i==0){
            while(n%i==0)
                n/=i;
            res-=res/i;
        }
    if(n>1)
        res-=res/n;
    return res;
}
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a/gcd(a,b))*b;
}
int binaryPow(int n,int pow){
    if(pow==0)
        return 1;
    if(pow%2==1)
        return binaryPow(n,pow-1)*n;
    else{
        int m=binaryPow(n,pow/2);
        return m*m;
    }
}
vector<bool> sieve(int n){
    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<=n;i++)
        if(prime[i])
            for(int j=i*i;j<=n;j+=i)
                prime[j]=false;
    return prime;
}   