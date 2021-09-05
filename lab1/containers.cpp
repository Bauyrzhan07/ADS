#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<stack<int>>containers;
    for(int i=0;i<n;i++){
        int k,temp;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>temp;
            containers[i].push(temp);
            
        }
    }
    return 0;
}