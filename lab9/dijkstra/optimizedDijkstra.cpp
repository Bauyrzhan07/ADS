#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int inf = 1e9;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,s;cin>>n>>m;
        vector<vector<pair<int,int>>>g(n);
        for(int i=0;i<m;i++){
            int a,b,c;cin>>a>>b>>c;
            g[a].push_back(make_pair(b,c));
            g[b].push_back(make_pair(a,c));
        }
        cin>>s;
        vector<int>d (n,inf);
        d[s] = 0;
        set<pair<int,int>> q;
        q.insert (make_pair (d[s], s));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase (q.begin());
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first, len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    q.erase (make_pair (d[to], to));
                    d[to] = d[v] + len;
                    q.insert (make_pair (d[to], to));
                }
            }
        }
        for(int i=0;i<n;i++){
            if(d[i]==inf)
                cout<<2009000999<<" ";
            else
                cout<<d[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}