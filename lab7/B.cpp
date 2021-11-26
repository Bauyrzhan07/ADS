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
    int k = 1;
    cin>>s;
    int n = s.length();
    vector<int> pi = pref_func(s);
    int sub_sz = n - pi[n-1];
    k = n / sub_sz;
    cout<< k;
    return 0;
}