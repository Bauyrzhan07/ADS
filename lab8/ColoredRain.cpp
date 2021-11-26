#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n,cnt = 0;
    cin>>n;
    vector<vector<int>>g(n);
    vector<int>colors(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp == 1)
                g[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++)
        cin>>colors[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<g[i].size();j++){
            int to = g[i][j];
            if(colors[i]!=colors[to])
                cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}