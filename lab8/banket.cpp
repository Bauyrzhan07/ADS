#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>g;
vector<int>cl;
bool bfs(int v){
    cl[v] = -1;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<g[cur].size();i++){
            int to = g[cur][i];
            if(cl[to] == 0){
                cl[to] = -cl[cur];
                q.push(to);
            }else if(cl[to] == cl[cur]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    g.resize(n);
    cl.assign(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    bool is_bipartite = true;
    for(int i=0;i<n;i++){
        if(cl[i] == 0)
            is_bipartite &= bfs(i);
    }
    if(is_bipartite){
        cout<<"YES\n";
        for(int i=0;i<n;i++)
            if(cl[i]==-1)
                cout<<i+1<<" ";
    }else
        cout<<"NO\n";
    return 0;
}