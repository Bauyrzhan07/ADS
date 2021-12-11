#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int K = 26;
const int N = 1e6;
set<string>words;
struct vertex{
    int next[K],cnt;
    bool leaf;
};

vertex t[N];
int sz;
void init(){
    for(int j = 0; j < K; ++j)
        t[0].next[j] = -1;  
    t[0].cnt = 0;
    sz = 1;
}
void add_string(string s){
    int v = 0;
    words.insert(s);
    for(size_t i=0;i<s.length();i++){
        int c = s[i] - 'a';//Depend on alphabet
        if(t[v].next[c]==-1){
            for(int j = 0; j < K; ++j){
                t[sz].next[j] = -1;   
                t[sz].cnt = 0;
            }
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
        t[v].cnt++;
    }
    t[v].leaf = true;
}
int find(string s){
    int v = 0;
    for(size_t i=0;i<s.length();i++){
        int c = s[i] - 'a';
        if(t[v].next[c]==-1)
            return 0;
        v = t[v].next[c];
    }
    return t[v].cnt;
}
void remove(string s){
    int v = 0;
    if(words.find(s)!=words.end()){
        for(size_t i=0;i<s.length();i++){
            int c = s[i] - 'a';
            if(t[v].next[c]==-1)
                return;
            v = t[v].next[c];
            t[v].cnt--;
        }
        words.erase(s);
    }else return;
}

int main(){
    int n;cin>>n;
    init();
    for(int i=0;i<n;i++){
        string command,tmp;cin>>command>>tmp;
        if(command=="+"){
            add_string(tmp);
        }else if(command=="-"){
            remove(tmp);
        }else if(command=="?"){
            cout<<find(tmp)<<endl;
        }
    }
    return 0;
}