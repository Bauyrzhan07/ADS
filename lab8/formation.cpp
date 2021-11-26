#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>cl;
vector<vector<int>>g;
vector<bool>used;
vector<int>ans;
void dfs(int v){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to])
            dfs(to);
    }
    ans.push_back(v+1);
}
bool check(int v){
    cl[v] = 1;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(cl[to] == 0){
            if(check(to))
                return true;
        }else if(cl[to] == 1)
            return true;
    }
    cl[v] = 2;
    return false;
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
    }
    bool has_cycle = false;
    for(int i=0;i<g.size();i++){
        if(check(i)){
            has_cycle = true;
            break;
        }
    }
    if(!has_cycle){
        cout<<"Yes\n";
        used.assign(n,false);
        for(int i=0;i<n;i++)
            if(!used[i])
                dfs(i);
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
            cout<<it<<" ";
    }else
        cout<<"No\n";
    return 0;
}