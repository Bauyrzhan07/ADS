#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int inf = 1e9;
int main(){
    int n;cin>>n;
    vector<vector<pair<int,int>>>g(n);
    vector<pair<int,int>>vertices(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        vertices[i] = make_pair(x,y);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            int xi = vertices[i].first, yi = vertices[i].second;
            int xj = vertices[j].first, yj = vertices[j].second;
            int req = abs(xi-xj) + abs(yi-yj);
            g[i].push_back(make_pair(j,req));
        }
    }
    vector<int>d(n,inf);
    set<pair<int,int>>s;
    d[0] = 0;
    s.insert(make_pair(d[0],0));
    for(int i=0;i<n;i++){
        int v = s.begin()->second;
        s.erase(s.begin());
        for(int j=0;j<g[v].size();j++){
            int to = g[v][j].first, len = g[v][j].second;            
            if(d[to]>max(d[v],len)){
                s.erase(make_pair(d[to],to));
                d[to] = max(d[v],len);
                s.insert(make_pair(d[to],to));
            }
        }
    }
    cout<<d[n-1];
    return 0;
}