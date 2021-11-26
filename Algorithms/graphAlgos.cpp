#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>g,gr;
vector<bool>used;
vector<int>order,component;
//Топологическая сортировка
void topsort(int v){
    used[v] = true;
    for(size_t i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to])
            topsort(to);
    }
    order.push_back(v);
}
//Поиск вершин компонента сильной связности
void generate_component(int v){
    used[v] = true;
    component.push_back(v);
    for(size_t i=0;i<gr[v].size();i++){
        int to = gr[v][i];
        if(!used[to])
            generate_component(to);
    }
}
//Поиск компонент сильной связности
void findStrongConnectivityComponents(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        gr[b-1].push_back(a-1);
    }
    used.assign(n,false);
    //Проводим топологическую сортировку для вершин графа
    for(int i=0;i<n;i++)
        if(!used[i])
            topsort(i);
    used.assign(n,false);
    int comp_index = 1;
    for(int i=0;i<n;i++){
        int v = order[n-i-1];
        if(!used[v]){
            generate_component(v);
            cout<<"Strong connectivity component "<<comp_index<<" consist of:\n";
            for(int i=0;i<component.size();i++)
                cout<<component[i]<<" ";
            cout<<'\n';
            component.clear();
        }
    }
}