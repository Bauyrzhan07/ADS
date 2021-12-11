#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>>e;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>res;
    vector<int>tree_id(n);
    for(int i=0;i<n;i++)
        tree_id[i] = i;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        e.push_back(make_pair(a-1,b-1));
    }
    for(int i=0;i<m;i++){
        int a = e[i].first, b = e[i].second;
        if(tree_id[a]!=tree_id[b]){
            res.push_back(make_pair(a,b));
            int old_id = tree_id[b],new_id = tree_id[a];
            for(int j=0;j<n;j++)
                if(tree_id[j]==old_id)
                    tree_id[j] = new_id;
        }
    }
    for(auto [a,b]:res)
        cout<<a+1<<" "<<b+1<<endl;
    return 0;
}