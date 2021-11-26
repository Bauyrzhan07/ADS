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

vector<int> find_substring(string t,string s){
    vector<int> ans;
    string nS = t+'#'+s;
    vector<int> pi;
    pi = pref_func(nS);
    for(int i = t.length() + 1;i < nS.length(); ++i){
        if(pi[i] == t.length())
            ans.push_back(i-2*t.length());
    }
    return ans;
}



int main(){
    string s,t;
    cin>>s>>t;
    vector<int> pi;
    pi = find_substring(t,s);
    for(auto it:pi)
        cout<<it<<" ";
}