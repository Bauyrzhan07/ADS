#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>g;
vector<int>used;
void dfs(int v){
    used[v] = 1;
    for(int i=0;i<g[v].size();i++)
        if(!used[g[v][i]])
            dfs(g[v][i]);
}
int main(){
    int n,m;cin>>n>>m;
    g.resize(n);
    used.resize(n);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    int cnt = 0;
    for(int i=0;i<n;i++)
        if(!used[i]){
            dfs(i);
            cnt++;
        }
    cout<<cnt-1;
    return 0;
}