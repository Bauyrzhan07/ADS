#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
map<int,int> p;
const int N = 1e5;
vector<bool>used;
int main(){
    int a,b;cin>>a>>b;
    queue<int>q;
    used.assign(N,false);
    q.push(a);
    while(!q.empty()){
        int cur_num = q.front();
        q.pop();
        if(cur_num==b)
            break;
        if(!used[cur_num*2]&&cur_num<10000){
            q.push(cur_num*2);
            used[cur_num*2] = true;
            p[cur_num*2] = cur_num;
        }
        if(!used[cur_num-1]&&cur_num>1){
            q.push(cur_num-1);
            used[cur_num-1] = true;
            p[cur_num-1] = cur_num;
        }
    }
    vector<int>path;
    for(int v=b;v!=a;v=p[v])
        path.push_back(v);
    cout<<path.size()<<endl;
    for(int i=0;i<path.size();i++)
        cout<<path[path.size()-i-1]<<" ";
    return 0;
}