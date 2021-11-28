#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>

const int inf = 1e9;

#define mp make_pair
#define pb push_back

using namespace std;

vector<vector<int>>g,gr;
vector<bool>used;
vector<int>order,component;  

//структура ребра
struct edge{
    int a,b,cost;
};

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
void generate_component(int v,vector<vector<int>>gr){
    used[v] = true;
    component.push_back(v);
    for(size_t i=0;i<gr[v].size();i++){
        int to = gr[v][i];
        if(!used[to])
            generate_component(to,gr);
    }
}
//Поиск компонент сильной связности
void findStrongConnectivityComponents(vector<vector<int>>g,vector<vector<int>>gr){
    int n = g.size();
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
            generate_component(v,gr);
            cout<<"Strong connectivity component "<<comp_index<<" consist of:\n";
            for(int i=0;i<component.size();i++)
                cout<<component[i]<<" ";
            cout<<'\n';
            component.clear();
        }
    }
    used.clear();
}
void printPath(vector<int>p,int s,int t){
    vector<int>path;
    for(int v=t;v!=s;v=p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(),path.end());
    for(auto v:path)
        cout<<v<<" ";
}
//Алгоритм Дейкстры O(N^2+M)
void dijkstra(vector<vector<pair<int,int>>>g){
    int s; cin>>s;//стартовая вершина
    int n = g.size();
    vector<int>d(n,inf),p(n);
    d[s] = 0;
    for(int i=0;i<n;i++){
        int v = -1;
        for(int j=0;j<n;j++)
            if(!used[j]&&(v==-1||d[j]<d[v]))
                v = j;
        if(d[v]==inf)
            break;
        used[v] = true;
        for(size_t j=0;j<g[v].size();j++){
            int to = g[v][j].first;
            int len = g[v][j].second;
            if(d[v]+len<d[to]){//релоксация
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    used.clear();
    int t;cin>>t;//ввод вершины до которой нам надо вывести минимальный путь в данном графе
    printPath(p,s,t);//вывод данного пути 
}

//Если нам даётся разреженный граф(когда m-количество ребер графа значительно меньше всех возможнхы ребер n^2), можно воспользоваться
//следующими вариациями алгоритма Дейкстры O(MlogN)

void Dijkstra_set(vector<vector<pair<int,int>>>g){
    int n = g.size();
    int s;cin>>s;//стартовая вершина
    vector<int> d(n,inf),p(n);
    d[s] = 0;
    set<pair<int,int>>q;//создаём очередь из вершин с помощью структуры set
    q.insert(mp(d[s],s));//добавляем стартовую вершину в нашу очередь
    while(!q.empty()){
        int v = q.begin()->second;// в переменной v храним номер текущей вершины
        q.erase(q.begin());//удаляем нашу вершину с очереди

        for(size_t i=0;i<g[v].size();i++){
            int to = g[v][i].first;
            int len = g[v][i].second;
            if(d[v]+len<d[to]){//релоксация
                q.erase(mp(d[to],to));//если у нас данная вершина уже хранится внутри очереди, мы её удаляем
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(mp(d[to],to));
            }
        }
    }
    int t;cin>>t;//ввод вершины до которой нам надо вывести минимальный путь в данном графе
    printPath(p,s,t);//вывод данного пути 
}

void Dijkstra_pqueue(vector<vector<pair<int,int>>>g){
    int n = g.size();
    int s;cin>>s;//стартовая вершина
    vector<int> d(n,inf),p(n);
    d[s] = 0;
    priority_queue<pair<int,int>>q;//создаём очередь из вершин с помощью структуры set
    q.push(mp(d[s],s));//добавляем стартовую вершину в нашу очередь
    while(!q.empty()){
        int v = q.top().second;// в переменной v храним номер текущей вершины
        int cur_dist = -q.top().first;//в данной перменной мы храним минимальную дистанцию до нашей текушей переменной
        //- ставится спереди т.к. в приоритетной очереди они хранятся в отрицательном значении.
        q.pop();//удаляем нашу вершину с очереди
        if(cur_dist>d[v]) continue;//проверка на фиктивность данного расстояния
        for(size_t i=0;i<g[v].size();i++){
            int to = g[v][i].first;
            int len = g[v][i].second;
            if(d[v]+len<d[to]){//релоксация
                d[to] = d[v] + len;
                p[to] = v;
                q.push(mp(-d[to],to));//как говорилось ранее, расстояние в нашей очереди хранятся в отрицательных значениях чтобы соблюдать 
                //корректность очереди.
            }
        }
    }
    int t;cin>>t;//ввод вершины до которой нам надо вывести минимальный путь в данном графе
    printPath(p,s,t);//вывод данного пути 
}

//Алгоритм Форда-Беллмана(применяется для графов содержащих ребра с отрицательными весами) O(NM)
void Ford_Bellman(vector<edge>e,int n){
    vector<int>d(n,inf),p(n,-1);
    int s; cin>>s;//стартовая вершина
    int m = e.size();
    d[s] = 0;
    while(true){
        bool any = false;//булевая переменная проверяющая изменения на данной фазе цикла
        for(int j=0;j<m;j++){
            if(d[e[j].a]<inf)
                if(d[e[j].b]>d[e[j].a]+e[j].cost){
                    d[e[j].b] = d[e[j].a]+e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        }
        if(!any)//если на данной фазе не произошло ни одного изменения, то мы завершаем работу нашего цикла
            break;
    }
    int t;cin>>t;//ввод вершины до которой нам надо вывести минимальный путь в данном графе
    printPath(p,s,t);//вывод данного пути 
}

//Алгоритм Флойда-Уоршелла() O(N^3)
void Floyd_Warshall(vector<vector<int>>d){
    int n = d.size();
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]<inf&&d[k][j]<inf)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    
}