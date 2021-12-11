#include<iostream>
#include<vector>
using namespace std;
const int inf = 1e9;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,pair<int,int>>>> g(n);
    for(int i=0;i<m;i++){
        int a,b,c,d;cin>>a>>b>>c>>d;
        g[a-1].push_back(make_pair(b-1,make_pair(c,(d-3000000)/100)));
        g[b-1].push_back(make_pair(a-1,make_pair(c,(d-3000000)/100)));
    }
    int d[n][1440];
    for(int i=0;i<n;i++)
        for(int j=0;j<1440;j++)
            d[i][j] = -1;
    vector<int>dist(n,inf);
    dist[0] = 0;
    d[0][0] = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            int to = g[i][j].first, time = g[i][j].second.first, items = g[i][j].second.second;
            dist[j] = dist[i] + time;
            int x = d[i][dist[i]] - items;
            d[to][dist[j]] = max(d[to][dist[j]],d[i][dist[i]] - x);
        }      
    }
    cout<<d[n-1][dist[n-1]];
    return 0;
}