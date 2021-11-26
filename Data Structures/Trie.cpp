#include<iostream>
#include <string.h>
using namespace std;
const int K = 26;
const int N = 1e6;
struct vertex{
    int next[K];
    bool leaf;
};

struct Trie{
    vertex t[N];
    int sz;
    void init(){
        for(int j = 0; j < K; ++j)
            t[0].next[j] = -1;  
        sz = 1;
    }
    void add_string(string& s){
        int v = 0;
        for(size_t i=0;i<s.length();i++){
            int c = s[i] - 'a';//Depend on alphabet
            if(t[v].next[c]==-1){
                for(int j = 0; j < K; ++j)
                    t[sz].next[j] = -1;
                t[v].next[c] = sz++;  
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
    }
};