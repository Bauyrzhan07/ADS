#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<bool> used;
vector<vector<int>> g;
int dfs(int v){
    used[v] = true;
    int cnt = 1;
    for(size_t i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to]){
            cnt += dfs(to);
        }
    }
    return cnt;
}
int main(){
    int n,s;
    cin>>n>>s;
    g.resize(n);
    used.assign(n,false);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp == 1)
                g[i].push_back(j);
        }
    int cnt = dfs(s-1);
    cout<<cnt<<'\n';
    return 0;
}