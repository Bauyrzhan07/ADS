#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        int n = s.length(),m = p.length();
        vector<int> pi(n+m+1);
        vector<int> ans;
        string sp = p + "#" + s;
        for(int i=1;i<sp.length();i++){
            int j = pi[i-1];
            while(j>0 && sp[i]!=sp[j])
                j = pi[j-1];
            if(sp[i]==sp[j])
                ++j;
            pi[i] = j;
        }
        for(int i=m+1;i<sp.length();i++){
            if(pi[i]==m)
                ans.push_back(i-2*m+1);
        }
        if(ans.size()==0)
            cout<<"Not Found\n";
        else{
            cout<<ans.size()<<'\n';
            for(auto it:ans)
                cout<<it<<" ";
            cout<<'\n';
        }
    }
    return 0;
}