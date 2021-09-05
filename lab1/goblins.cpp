#include<iostream>
#include<deque>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,temp;
    deque<int> tempDeq;
    cin>>n;
    string oper;
    deque<int> q;
    while(n--){
        cin>>oper;
        if(oper=="+"){
            cin>>temp;
            q.push_back(temp);
        }else if(oper=="*"){
            cin>>temp;
            q.push_front(temp);
        }else{
            cout<<tempDeq.front()<<endl;
            tempDeq.pop_front();
        }
        if(q.size()>tempDeq.size()){
            tempDeq.push_back(q.front());
            q.pop_front();
        }
    }
    return 0;
}