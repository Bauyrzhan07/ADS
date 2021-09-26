#include<iostream>
using namespace std;
int main(){
    int temp,n,max=-2147483647,prev_max;;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>prev_max&&temp<max){
            prev_max=temp;
        }
        else if(temp>max){
            prev_max=max;
            max=temp;
        }
    }
    cout<<prev_max;
    return 0;
}