#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
map<int,int>p;
void bfs(int st,int f){
    queue<int>q;
    q.push(st);
    int i = 0;
    while(q.front()!=f){     
        int s = q.front();
        q.pop();
        if(s%10!=1){
            if(p[s+1]==-1){
                p[s+1] = s;
                q.push(s+1);
            }
        }
        if(s/1000!=9){
            if(p[s+1000]==-1){
                p[s+1000] = s;
                q.push(s+1000);
            }
        }
        int s1 = (s%1000)*10 + s/1000;
        if(p[s1]==-1){
            p[s1] = s;
            q.push(s1);
        }
        s1 = s/10 + (s%10)*1000;
        if(p[s1]==-1){
            p[s1] = s;
            q.push(s1);
        }
    }
}
int main(){
    int s,f;
    cin>>s>>f;
    for(int i=1000;i<=9999;i++)
        p[i] = -1;
    p[s] = 0;
    bfs(s,f);
    vector<int>path;
    for(int v=f;v!=0;v=p[v])
        path.push_back(v);
    for(vector<int>::reverse_iterator it = path.rbegin();it!=path.rend();it++)
        cout<<*it<<"\n";
    return 0;
}