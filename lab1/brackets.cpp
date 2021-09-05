#include<iostream>
#include<stack>
using namespace std;
int main(){
    string brackets;
    stack<int> br;
    cin>>brackets;
    for(int i=0;i<brackets.length();i++){
        if(br.empty())
            br.push(brackets[i]);
        else if(br.top()=='('&&brackets[i]==')')
            br.pop();
        else if(br.top()=='['&&brackets[i]==']')
            br.pop();
        else if(br.top()=='{'&&brackets[i]=='}')
            br.pop();
        else
            br.push(brackets[i]);
    }
    if(br.empty())
        cout<<"yes\n";
    else
        cout<<"no\n";
    return 0;
}