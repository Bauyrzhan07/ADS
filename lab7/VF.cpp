#include<bits/stdc++.h>
using namespace std;
int pref(string s){
    vector<int> pi(s.length());
    int maxi = 0;
    for(int i=1;i<s.length();i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
            j = pi[j-1];
        if(s[i]==s[j])
            ++j;
        pi[i]=j;
        maxi = max(pi[i],maxi);
    }
    return maxi;
}
int main(){
    string s;
    cin>>s; 
    string t = "";
    int ans = 0;
    for(int i=0;i<s.length();i++){
        t=s[i]+t;
        int p_max = pref(t);
        ans += t.length()-p_max;
    }
    cout<<ans<<'\n';
    return 0;
}