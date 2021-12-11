#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<pair<int,int>>>g(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;cin>>tmp;
            if(tmp!=0)
                g[i].push_back(make_pair(j,tmp));
        }
    }
    vector<int> val(n);
    for(int i=0;i<n;i++)
        cin>>val[i];
    int f=-1,s=-1,mn=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            int to = g[i][j].first, len = g[i][j].second;
            if(val[to]!=val[i]&&len<mn){
                mn = len;
                if(val[i]==0){
                    f = i;
                    s = to;
                }else{
                    f = to;
                    s = i;
                }
            }
        }
    }
    cout<<f+1<<" "<<s+1;
    return 0;
}