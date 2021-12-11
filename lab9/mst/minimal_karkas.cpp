#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int>>>g;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        g.push_back(make_pair(c,make_pair(a-1,b-1)));
    }
    int cost = 0;
    vector<int>tree_id(n);
    for(int i=0;i<n;i++)
        tree_id[i] = i;
    sort(g.begin(),g.end());
    for(int i=0;i<m;i++){
        int a = g[i].second.first, b = g[i].second.second, len = g[i].first;
        if(tree_id[a]!=tree_id[b]){
            cost += len;
            int old_id = tree_id[b], new_id = tree_id[a];
            for(int j=0;j<n;j++)
                if(tree_id[j]==old_id)
                    tree_id[j] = new_id;
        }
    }
    cout<<cost;
    return 0;
}