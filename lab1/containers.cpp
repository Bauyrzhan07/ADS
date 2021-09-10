#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag=true;
    vector<stack<int>>containers;
    stack<int> tempStack;
    for(int i=0;i<n;i++){
        containers.push_back(tempStack);
        int k,temp;
        cin>>k;
        while(k--){
            cin>>temp;
            containers[i].push(temp);
            if(temp!=i+1)
                flag=false;
        }
    }
    if(flag)
        return 0;
    if(n<2)
        return 0;
    if(n==2){
        int cnt2=0,cnt1=0;
        while(!containers[1].empty()){
            containers[0].push(containers[1].top());
            containers[1].pop();
            cnt1++;
        }
        while(containers[0].top()==2){
            containers[1].push(2);
            containers[0].pop();
            cnt2++;
            if(containers[0].empty())
                break;
        }
        while(!containers[0].empty()){
            if(containers[0].top()==2){
                cout<<0;
                return 0;
            }
            containers[0].pop();
        }
        while(cnt1--)
            cout<<2<<" "<<1<<endl;
        while(cnt2--)
            cout<<1<<" "<<2<<endl;
    }
    else{
        for(int i=1;i<n;i++){
            while(!containers[i].empty()){
                containers[0].push(containers[i].top());
                cout<<i+1<<" "<<1<<endl;
                containers[i].pop();
            }
        }
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(!containers[n-1].empty()){
                    while(containers[n-1].top()==n-1){
                        containers[n-2].push(n-1);
                        containers[n-1].pop();
                        cout<<n<<" "<<n-1<<endl;
                        if(containers[n-1].empty())
                            break;
                    }
                }
            }
            else{
                while(!containers[i].empty()){
                    if(containers[i].top()==i+1){
                        containers[i+1].push(containers[i].top());
                        containers[i].pop();
                        cout<<i+1<<" "<<i+2<<endl;
                    }
                    else{
                        containers[containers[i].top()-1].push(containers[i].top());
                        cout<<i+1<<" "<<containers[i].top()<<endl;
                        containers[i].pop();
                    }
                }
            }
        }
        
    }
    return 0;
}