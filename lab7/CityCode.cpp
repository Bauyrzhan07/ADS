#include<iostream>
#include<string.h>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
const int K = 10;
const int N = 1e6;
map<string,int>count;
struct vertex{
    int next[K];
    bool is_city;
    string city = "None";
};
vertex t[N];
int sz;
void init(){
    for(int j = 0; j < K; ++j)
        t[0].next[j] = -1;
    sz = 1;
}
void add_string(string s,string city,int m){
    int v = 0;
    string parent = "None";
    for(size_t i=0;i<s.length();i++){
        int c = s[i] - '0';
        if(t[v].next[c]==-1){
            for(int j = 0; j < K; ++j)
                t[sz].next[j] = -1;
            t[v].next[c] = sz++;
        }
        if(t[v].is_city)
            parent = t[v].city;
        v = t[v].next[c];
    }
    t[v].is_city = true;
    t[v].city = city;
    count[city] = pow(10,m-s.size());
    if(parent!="None")
        count[parent] -= count[city];
}
int main(){
    int n,m;
    cin>>n>>m;
    init();
    vector<string>cities;
    while(n--){
        string code,city;
        cin>>code>>city;
        cities.push_back(city);
        add_string(code,city,m);
    }
    for(auto city:cities)   
        cout<<city<<" "<<count[city]<<'\n';
    return 0;
}