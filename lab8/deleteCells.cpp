#include<iostream>
#include<map>
using namespace std;
int n,m;
map<pair<int,int>,bool>used;
void dfs(int i,int j,string cells[]){
    used[{i,j}] = true;
    if(i+1<m&&!used[{i+1,j}]&&cells[i+1][j]=='#')
        dfs(i+1,j,cells);
    if(i-1>=0&&!used[{i-1,j}]&&cells[i-1][j]=='#')
        dfs(i-1,j,cells);
    if(j+1<n&&!used[{i,j+1}]&&cells[i][j+1]=='#')
        dfs(i,j+1,cells);
    if(j-1>=0&&!used[{i,j-1}]&&cells[i][j-1]=='#')
        dfs(i,j-1,cells);
}
int main(){
    cin>>m>>n;
    string cells[m];
    int cnt = 0;
    for(int i=0;i<m;i++)
        cin>>cells[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!used[{i,j}]&&cells[i][j]=='#'){
                dfs(i,j,cells);
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    
    return 0;
}