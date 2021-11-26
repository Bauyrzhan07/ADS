#include<iostream>
#include<vector>
using namespace std;
vector<int> pref_func(string s){
    int n = s.length();
    vector<int> pi(n);
    for(size_t i = 1; i < n; ++i){
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
    string s;
    cin>>s;
    vector<int> ans;
    ans = pref_func(s);
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}