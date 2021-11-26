#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int p = 31;
vector<int> p_pow(10000);

void count_pows(){
    p_pow[0]=1;
    for(size_t i = 1; i < p_pow.size(); ++i){
        p_pow[i] = p * p_pow[i-1];
    }
}

long long hashing(string s){
    long long hash = 0;
    for(size_t i = 0; i < s.length(); ++i){
        hash += (s[i] - 'a' + 1) * p_pow[i];
    }    
    return hash;
}

long long substring_hashing(int i, int j, string s){
    int length = s.length();
    vector<long long> hashes(length);
    for(size_t i = 0; i < length; ++i){
        hashes[i] = (s[i] - 'a' + 1) * p_pow[i];
        if(i > 0){
            hashes[i] += hashes[i-1];
        }
    }
    long long h = hashes[j];
    h -= hashes[i-1];
    return h;
}

void search_for_equal_strings(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(size_t i = 0; i < n; ++i){
        string s_temp;
        cin>>s_temp;
        s.push_back(s_temp);
    }
    vector<pair<int,int>>hashes(n);
    for(size_t i = 0; i < n; ++i){
        hashes[i] = make_pair(hashing(s[i]),i);
    }
    sort(hashes.begin(),hashes.end());
    for(size_t i = 0, group = 0; i < n; ++i){
        if(i == 0|| hashes[i].first != hashes[i-1].first){
            cout << "\n Group " << ++group << ':';
        }
        cout << hashes[i].second << ' ';
    }
}
