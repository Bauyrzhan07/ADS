#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>g;
vector<bool>used;
vector<int>cmp;
void dfs(int v){
    used[v] = true;
    cmp.push_back(v+1);
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to])
            dfs(to);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    used.assign(n,false);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<vector<int>>cmps;
    for(int i=0;i<n;i++){
        cmp.clear();
        if(!used[i]){
            dfs(i);
            cmps.push_back(cmp);
        }
    }
    cout<<cmps.size()<<'\n';
    for(int i=0;i<cmps.size();i++){
        cout<<cmps[i].size()<<'\n';
        for(auto v:cmps[i])
            cout<<v<<" ";
        cout<<'\n';
    }
    return 0;
}