#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> first,second;
    int temp,round=0;
    for(int i=0;i<5;i++){
        cin>>temp;
        first.push_back(temp);
    }
    for(int i=0;i<5;i++){
        cin>>temp;
        second.push_back(temp);
    }
    while(true){
        if((first.front()==9&&second.front()==0)){
            second.push_back(first.front());
            second.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }else if(first.front()==0&&second.front()==9){
            first.push_back(first.front());
            first.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }else if(second.front()>first.front()){
            second.push_back(first.front());
            second.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }else if(second.front()<first.front()){
            first.push_back(first.front());
            first.push_back(second.front());
            first.pop_front();
            second.pop_front();
        }
        round++;
        if(first.empty()){
            cout<<"second "<<round;
            break;
        }
        else if(second.empty()){
            cout<<"first "<<round;
            break;
        }
        else if(round==1000000){
            cout<<"botva";
            break;   
        }
    }
    
    return 0;
}