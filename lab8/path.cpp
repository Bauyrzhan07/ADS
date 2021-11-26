#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>>g;
vector<bool>used;
vector<int>p;
void bfs(int st,int end){
    int n = g.size();
    vector<bool>used(n);
    vector<int> d(n),p(n);
    queue<int> q;
    q.push(st);
    p[st] = -1;
    used[st] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++){
            int to = g[v][i];
            if(!used[to]){
                used[to] = true;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    if(!used[end])
        cout<<-1<<'\n';
    else{
        cout<<d[end]<<'\n';
        vector<int>path;
        for(int i=end;i!=-1;i=p[i])
            path.push_back(i+1);
        reverse(path.begin(),path.end());
        for(auto v:path)
            cout<<v<<" ";
    }
}
int main(){
    int n,a,b;
    cin>>n;
    g.resize(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp) g[i].push_back(j);
        }
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return 0;
    }
    bfs(a-1,b-1);
    return 0;
}