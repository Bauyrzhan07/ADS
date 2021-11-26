#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
int chess[20][20];
int n,x1,y1,x2,y2;
void bfs(){
    queue<pair<int,int>>q;
    map<pair<int,int>,pair<int,int>>p;
    p[{x1-1,y1-1}] = {-1,-1};
    q.push({x1-1,y1-1});
    while(chess[x2-1][y2-1]==-1){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first+2<n&&cur.second+1<n&&chess[cur.first+2][cur.second+1]==-1){
            chess[cur.first+2][cur.second+1] = chess[cur.first][cur.second] + 1;
            q.push({cur.first+2,cur.second+1});
            p[{cur.first+2,cur.second+1}] = {cur.first,cur.second};
        }
        if(cur.first+1<n&&cur.second+2<n&&chess[cur.first+1][cur.second+2]==-1){
            chess[cur.first+1][cur.second+2] = chess[cur.first][cur.second] + 1;
            q.push({cur.first+1,cur.second+2});
            p[{cur.first+1,cur.second+2}] = {cur.first,cur.second};
        }
        if(cur.first-2>=0&&cur.second-1>=0&&chess[cur.first-2][cur.second-1]==-1){
            chess[cur.first-2][cur.second-1] = chess[cur.first][cur.second] + 1;
            q.push({cur.first-2,cur.second-1});
            p[{cur.first-2,cur.second-1}] = {cur.first,cur.second};
        }
        if(cur.first-1>=0&&cur.second-2>=0&&chess[cur.first-1][cur.second-2]==-1){
            chess[cur.first-1][cur.second-2] = chess[cur.first][cur.second] + 1;
            q.push({cur.first-1,cur.second-2});
            p[{cur.first-1,cur.second-2}] = {cur.first,cur.second};
        }
        if(cur.first-2>=0&&cur.second+1<n&&chess[cur.first-2][cur.second+1]==-1){
            chess[cur.first-2][cur.second+1] = chess[cur.first][cur.second] + 1;
            q.push({cur.first-2,cur.second+1});
            p[{cur.first-2,cur.second+1}] = {cur.first,cur.second};
        }
        if(cur.first+2<n&&cur.second-1>=0&&chess[cur.first+2][cur.second-1]==-1){
            chess[cur.first+2][cur.second-1] = chess[cur.first][cur.second] + 1;
            q.push({cur.first+2,cur.second-1});
            p[{cur.first+2,cur.second-1}] = {cur.first,cur.second};
        }
        if(cur.first-1>=0&&cur.second+2<n&&chess[cur.first-1][cur.second+2]==-1){
            chess[cur.first-1][cur.second+2] = chess[cur.first][cur.second] + 1;
            q.push({cur.first-1,cur.second+2});
            p[{cur.first-1,cur.second+2}] = {cur.first,cur.second};
        }
        if(cur.first+1<n&&cur.second-2>=0&&chess[cur.first+1][cur.second-2]==-1){
            chess[cur.first+1][cur.second-2] = chess[cur.first][cur.second] + 1;
            q.push({cur.first+1,cur.second-2});
            p[{cur.first+1,cur.second-2}] = {cur.first,cur.second};
        }
    }
    cout<<chess[x2-1][y2-1]<<'\n';
    vector<pair<int,int>>path;
    for(pair<int,int> v = {x2-1,y2-1};v!=make_pair(-1,-1);v = p[v])
        path.push_back(v);
    reverse(path.begin(),path.end());
    for(auto v:path)
        cout<<v.first+1<<" "<<v.second+1<<'\n';
}
int main(){
    cin>>n>>x1>>y1>>x2>>y2;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            chess[i][j]=-1;
    chess[x1-1][y1-1] = 0;
    bfs();
    return 0;
}