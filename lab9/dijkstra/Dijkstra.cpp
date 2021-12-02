#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,s,f; cin>>n>>s>>f;
    vector<vector<pair<int,int>>>g(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;cin>>tmp;
            if(tmp>0)
                g[i].push_back(make_pair(j,tmp));
        }
    }
    vector<int> d(n,1e8),p(n);
    vector<bool>used(n);
    d[s-1] = 0;
    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=0;j<n;j++){
            if(!used[j]&&(v==-1||d[j]<d[v]))
                v = j;
        }
        if(d[v] == 1e8)
            break;
        used[v] = true;
        for(size_t j=0;j<g[v].size();j++){
            int to = g[v][j].first, len =g[v][j].second;
            if(d[v]+len<d[to]){
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    if(d[f-1] == 1e8)
        cout<<-1<<'\n';
    else{
        vector<int> path;
        for (int v=f-1; v!=s-1; v=p[v])
            path.push_back(v);
        path.push_back(s-1);
        reverse (path.begin(), path.end());
        for(auto p:path)
            cout<<p+1<<" ";
    }
    return 0;
}