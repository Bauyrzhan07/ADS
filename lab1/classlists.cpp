#include<iostream>
#include<vector>
using namespace std;
int main(){
    int temp;
    string temp_name;
    vector<pair<int,string>> class9,class10,class11;
    while(cin>>temp>>temp_name){
        if(temp==9){
            class9.push_back(make_pair(temp,temp_name));
        }
        if(temp==10){
            class10.push_back(make_pair(temp,temp_name));
        }
        if(temp==11){
            class11.push_back(make_pair(temp,temp_name));
        }
    }
    for(auto it:class9)
        cout<<it.first<<" "<<it.second<<endl;
    for(auto it:class10)
        cout<<it.first<<" "<<it.second<<endl;
    for(auto it:class11)
        cout<<it.first<<" "<<it.second<<endl;
    
}