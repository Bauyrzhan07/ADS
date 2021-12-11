#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>g;
vector<int>colors;
bool dfs(int v,int p = -1){
    colors[v] = 1;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(colors[to] == 0){
            if(dfs(to,v))
                return true;
        }else if(colors[to] == 1 && to != p){
            return true;
        }
    }
    colors[v] = 2;
    return false;
}
int main(){
    int n,cnt = 0;
    cin>>n;
    g.resize(n);
    colors.assign(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp){
                g[i].push_back(j);
                cnt++;
            }
        }
    }
    bool is_tree = true;
    for(int i=0;i<n;i++)
        if(dfs(i)){
            is_tree = false;
            break;
        }
    
    if(is_tree&&cnt/2==n-1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}