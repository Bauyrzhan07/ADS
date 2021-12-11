#include<iostream>
#include<deque>
using namespace std;
int main(){
    string s;cin>>s;
    deque<char> dq;
    for(int i=0;i<s.length();i++){
        if(dq.empty())
            dq.push_back(s[i]);
        else if(dq.back()==s[i]){
            dq.pop_back();
        }else{
            dq.push_back(s[i]);
        }
    }
    if(dq.empty())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}