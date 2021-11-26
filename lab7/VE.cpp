#include<iostream>
#include<vector>
using namespace std;
vector<int> pref(string s){
    int n = s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
            j = pi[j-1];
        if(s[i]==s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}
int main(){
    string temp;
    while(true){
        cin>>temp;
        if(temp == ".")
            break;
        vector<int> pi = pref(temp);
        int i = temp.length() - pi[pi.size()-1];
        int cnt = temp.length()/i;
        cout<<cnt<<'\n';
    }
    return 0;
}