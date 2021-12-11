#include<iostream>
#include<vector>
using namespace std;
vector<int> pref_func(string s){
    int n = s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i){
        int j = pi[i-1];
        while(j > 0 && s[i] != s [j]){
            j = pi[j-1];
        }
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> p;
    p = pref_func(s+'#'+t);
    if(p.back()==0)
        cout<<-1;
    else
        cout<<n-p.back();
    return 0;
}