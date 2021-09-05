#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
            int temp2=st.top();
            st.pop();
            int temp1=st.top();
            st.pop();
            if(s[i]=='+')
                st.push(temp1+temp2);
            if(s[i]=='-')
                st.push(temp1-temp2);
            if(s[i]=='*')
                st.push(temp1*temp2);
        }
        else if(s[i]!=' '){
            st.push(int(s[i])-48);
        }
    }
    cout<<st.top();
    return 0;
}