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
struct qu{
    private:
        int queue_size;
        node* head;
        node* tail;
    public:
        qu(){
            head=NULL;
            tail=NULL;
            queue_size=0;
        }
        void push(int temp){
            node* item=new node(temp);
            queue_size++;
            if(head==NULL)
                head=item;
            else if(tail==NULL){
                tail=item;
                head->next=tail;
                tail->prev=head;
            }
            else{
                item->prev=tail;
                tail->next=item;
                tail=item;
            }
        }
        void pop(){
            if(head==NULL){
                cout<<"error"<<endl;
            }
            else if(head->next==tail){
                cout<<head->value<<endl;
                head=tail;
                tail=NULL;
                queue_size--;
            }
            else if(head->next==NULL){
                cout<<head->value<<endl;
                head=NULL;
                queue_size--;
            }
            else if(head!=NULL){
                cout<<head->value<<endl;
                head=head->next;
                head->prev=NULL;
                queue_size--;
            }
        }
        void front(){
            if(head==NULL)
                cout<<"error"<<endl;
            else
                cout<<head->value<<endl;
        }
        int size(){
            return queue_size;
        }
        void clear(){
            head=NULL;
            tail=NULL;
            queue_size=0;
        }

};
int main(){
    string command;
    qu myQueue;
    while(true){
        cin>>command;
        if(command=="push"){
            int temp;
            cin>>temp;
            myQueue.push(temp);
            cout<<"ok"<<endl;
        }
        if(command=="pop"){
            myQueue.pop();
        }
        if(command=="front"){
            myQueue.front();
        }
        if(command=="size")
            cout<<myQueue.size()<<endl;
        if(command=="clear"){
            myQueue.clear();
            cout<<"ok"<<endl;
        }
        if(command=="exit"){
            cout<<"bye";
            return 0;
        }
    }
}