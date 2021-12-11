#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 1e9;
vector<int>tree_id;
vector<bool>used;
vector<vector<int>>g;
void dfs(int v,int id){
    used[v] = true;
    tree_id[v] = id;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to])
            dfs(to,id);
    }
}
int main(){
    int n;cin>>n;
    vector<pair<int,pair<int,int>>>cost;
    int d[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>d[i][j];
            if(d[i][j]==0&&i!=j)
                d[i][j] = INF;
        }
    for (int k=0; k<n; ++k)
    	for (int i=0; i<n; ++i)
	    	for (int j=0; j<n; ++j)
		    	if (d[i][k] < INF && d[k][j] < INF)
			    	d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(d[i][j]!=0&&d[i][j]!=INF)
                cost.push_back(make_pair(d[i][j],make_pair(i,j)));
    g.resize(n);
    used.assign(n,false);
    tree_id.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;cin>>tmp;
            if(tmp!=0)
                g[i].push_back(j);
        }
    }
    int cmp_id = 0, res = 0;
    for(int i=0;i<n;i++){
        if(!used[i]){
            dfs(i,cmp_id);
            cmp_id++;
        }
    }
    sort(cost.begin(),cost.end());
    for(int i=0;i<n;i++){
        int a = cost[i].second.first, b = cost[i].second.second, price = cost[i].first;
        if(tree_id[a]!=tree_id[b]){
            res += price;
            int old_id = tree_id[b], new_id = tree_id[a];
            for(int j=0;j<n;j++)
                if(tree_id[j]==old_id)
                    tree_id[j] = new_id;
        }
    }
    cout<<res;
    return 0;
}