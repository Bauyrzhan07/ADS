#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;cin>>n;
    vector<int>fuel_cost(n);
    for(int i=0;i<n;i++)
        cin>>fuel_cost[i];
    cin>>m;
    vector<vector<pair<int,int>>>g(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a-1].push_back(make_pair(b-1,fuel_cost[a-1]));
        g[b-1].push_back(make_pair(a-1,fuel_cost[b-1]));
    }
    vector<int>d(n,1e9);
    vector<bool>used(n);
    d[0] = 0;
    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=0;j<n;j++)
            if(!used[j]&&(v==-1||d[v]>d[j]))
                v = j;
        if(d[v]==1e9)
            break;
        used[v] = true;
        for(size_t j=0;j<g[v].size();j++){
            int to = g[v][j].first, len = g[v][j].second;
            if(d[v]+len<d[to])
                d[to] = d[v] + len;
        }
    }
    if(d[n-1] == 1e9)
        cout<<-1<<'\n';
    else
        cout<<d[n-1]<<'\n';

    return 0;
}