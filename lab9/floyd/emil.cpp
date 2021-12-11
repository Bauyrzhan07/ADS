#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#define mp make_pair;
using namespace std;
const int INF = 1e9;
int main(){
    int k,n,m;cin>>n>>m;
    string a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>k;
    int min_cost = INF;
    map<pair<int,int>,pair<int,int>>p_f;
    for(int i=0;i<k;i++){
        map<pair<int,int>,pair<int,int>>p;
        int x,y;cin>>x>>y;
        int d[n][m];
        for(int j=0;j<n;j++)
            for(int l=0;l<m;l++)
                d[j][l] = -1;
        d[x-1][y-1] = 0;
        p[make_pair(x-1,y-1)] = {-1,-1};
        queue<pair<int,int>>q;
        q.push(make_pair(x-1,y-1));
        int res = -1;
        while(!q.empty()){
            int cx = q.front().first, cy = q.front().second;
            q.pop();
            if(a[cx][cy]=='*'){
                res = d[cx][cy];
                break;
            }
            if(cx+1<n&&a[cx+1][cy]!='1'&&d[cx+1][cy]==-1){
                d[cx+1][cy] = d[cx][cy] + 1;
                q.push(make_pair(cx+1,cy));
                p[make_pair(cx+1,cy)] = make_pair(cx,cy);
            }
            if(cx-1>=0&&a[cx-1][cy]!='1'&&d[cx-1][cy]==-1){
                d[cx-1][cy] = d[cx][cy] + 1;
                q.push(make_pair(cx-1,cy));
                p[make_pair(cx-1,cy)] = make_pair(cx,cy);
            }
            if(cy+1<m&&a[cx][cy+1]!='1'&&d[cx][cy+1]==-1){
                d[cx][cy+1] = d[cx][cy] + 1;
                q.push(make_pair(cx,cy+1));
                p[make_pair(cx,cy+1)] = make_pair(cx,cy);
            }
            if(cy-1>=0&&a[cx][cy-1]!='1'&&d[cx][cy-1]==-1){
                d[cx][cy-1] = d[cx][cy] + 1;
                q.push(make_pair(cx,cy-1));
                p[make_pair(cx,cy-1)] = make_pair(cx,cy);
            }
        }
        if(res!=-1&&res<min_cost){
            min_cost = res;
            p_f = p;
        }
    }
    int fx,fy;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='*'){
                fx = i;
                fy = j;
                break;
            }
    if(min_cost==INF){
        cout<<-1;
        return 0;
    }else
        cout<<min_cost<<endl;
    vector<pair<int,int>>path;
    for(pair<int,int> i=make_pair(fx,fy);i!=make_pair(-1,-1);i=p_f[i])
        path.push_back(i);
    reverse(path.begin(),path.end());
    for(auto p:path)
        cout<<p.first+1<<" "<<p.second+1<<"\n";
    return 0;
}