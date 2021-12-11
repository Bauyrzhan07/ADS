#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<pair<int,pair<int,int>>>g;
int Kruskal(){
    int cost = 0;
    vector<pair<int,int>>res;
    sort(g.begin(),g.end());
    vector<int> tree_id(n);
    for(int i=0;i<n;i++)
        tree_id[i] = i;
    for(int i=0;i<m;i++){
        int a = g[i].second.first, b = g[i].second.second, weight = g[i].first;
        if(tree_id[a]!=tree_id[b]){
            cost += weight;
            res.push_back(make_pair(a,b));
            int oid = tree_id[b], nid = tree_id[a];
            for(int j=0;j<n;j++)
                if(tree_id[j]==oid)
                    tree_id[j]=nid;
        }
    }
    return cost;
}
int main(){
    n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g.push_back(make_pair(c,make_pair(a-1,b-1)));
    }
    cout<<Kruskal();
    return 0;
}