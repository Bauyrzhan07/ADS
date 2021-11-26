#include<iostream>
#include<vector>
using namespace std;
int p = 31;
int main(){
    string s,t;
    cin>>t>>s;
    vector<long long> p_pow(t.size());
    p_pow[0] = 1;
    for(int i=1;i<t.size();i++)
        p_pow[i] = p_pow[i-1] * p;
    long long h_s = 0;
    for(int i=0;i<s.length();i++)
        h_s += s[i] * p_pow[i];
    vector<long long> t_pref_h(t.size());
    for(int i=0;i<t.length();i++){
        t_pref_h[i] = t[i] * p_pow[i];
        if(i) t_pref_h[i] += t_pref_h[i-1];
    }
    for(int i=0;i<t.length()-s.length()+1;i++){
        long long cur_h = t_pref_h[i+s.length()-1];
        if(i) cur_h -= t_pref_h[i-1];
        if(cur_h == h_s * p_pow[i])
            cout<<i<<" ";
    }
    return 0;
}