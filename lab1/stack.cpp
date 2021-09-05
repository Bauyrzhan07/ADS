#include<iostream>
using namespace std;
struct node{
    int value;
    node* next;
    node* prev;
    node(int temp){
        value=temp;
        next=NULL;
        prev=NULL;
    }
};
struct st{
    private:
        int stack_size;
        node* tail;
    public:
        st(){
            tail=NULL;
            stack_size=0;
        }
        void push(int temp){
            node* item=new node(temp);
            stack_size++;
            if(tail==NULL)
                tail=item;
            else{
                item->prev=tail;
                tail->next=item;
                tail=item;
            }
        }
        void pop(){
            if(tail==NULL){
                cout<<"error"<<endl;
            }
            else if(tail->prev==NULL){
                cout<<tail->value<<endl;
                tail=NULL;
                stack_size--;
            }
            else if(tail!=NULL){
                cout<<tail->value<<endl;
                tail=tail->prev;
                tail->next=NULL;
                stack_size--;
            }
        }
        void back(){
            if(tail==NULL)
                cout<<"error"<<endl;
            else
                cout<<tail->value<<endl;
        }
        int size(){
            return stack_size;
        }
        void clear(){
            tail=NULL;
            stack_size=0;
        }

};
int main(){
    string command;
    st myStack;
    while(true){
        cin>>command;
        if(command=="push"){
            int temp;
            cin>>temp;
            myStack.push(temp);
            cout<<"ok"<<endl;
        }
        if(command=="pop"){
            myStack.pop();
        }
        if(command=="back"){
            myStack.back();
        }
        if(command=="size")
            cout<<myStack.size()<<endl;
        if(command=="clear"){
            myStack.clear();
            cout<<"ok"<<endl;
        }
        if(command=="exit"){
            cout<<"bye";
            return 0;
        }
    }
}