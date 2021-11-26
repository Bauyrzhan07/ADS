#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int cnt = 0;
    while(s1!=s2){
        char c = s1[s1.length()-1];
        s1.pop_back();
        s1 = c + s1;
        cnt++;
        if(cnt == s1.length()){
            cnt = -1;
            break;
        }        
    }
    cout<<cnt;
    return 0;
}