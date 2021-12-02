#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
struct DSU{
    private:
    vector<int>p;
    vector<int>rank;
    public:
    void makeSet(int x){
        p[x] = x;
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(rand()%2==0)
            swap(x,y);
        p[x] = y;
    }
};