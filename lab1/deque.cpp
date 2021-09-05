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
struct dqu{
    private:
        int deque_size;
        node* head;
        node* tail;
    public:
        dqu(){
            head=NULL;
            tail=NULL;
            deque_size=0;
        }
        void push_back(int temp){
            node* item=new node(temp);
            deque_size++;
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
        void push_front(int temp){
            node* item=new node(temp);
            deque_size++;
            if(head==NULL)
                head=item;
            else if(tail==NULL){
                tail=head;
                head=item;
                head->next=tail;
                tail->prev=head;
            }
            else{
                item->next=head;
                head->prev=item;
                head=item;
            }
        }
        void pop_back(){
            if(tail==NULL)
                cout<<"error"<<endl;
            else if(tail->prev==NULL){
                cout<<tail->value<<endl;
                tail=NULL;
                deque_size--;
            }
            else if(tail==head){
                cout<<tail->value<<endl;
                tail=NULL;
                head=NULL;
                deque_size--;
            }
            else{
                cout<<tail->value<<endl;
                tail=tail->prev;
                tail->next=NULL;
                deque_size--;
            }
        }
        void pop_front(){
            if(head==NULL){
                cout<<"error"<<endl;
            }
            else if(tail==head){
                cout<<tail->value<<endl;
                tail=NULL;
                head=NULL;
                deque_size--;
            }
            else if(head->next==NULL){
                cout<<head->value<<endl;
                head=NULL;
                deque_size--;
            }
            else if(head!=NULL){
                cout<<head->value<<endl;
                head=head->next;
                head->prev=NULL;
                deque_size--;
            }
        }
        void front(){
            if(head==NULL&&tail!=NULL)
                cout<<tail->value<<endl;
            else if(head==NULL)
                cout<<"error"<<endl;
            else
                cout<<head->value<<endl;
        }
        void back(){
            if(tail==NULL&&head!=NULL)
                cout<<head->value<<endl;
            else if(tail==NULL)
                cout<<"error"<<endl;
            else
                cout<<tail->value<<endl;
        }
        int size(){
            return deque_size;
        }
        void clear(){
            head=NULL;
            tail=NULL;
            deque_size=0;
        }

};
int main(){
    string command;
    dqu myDeque;
    while(true){
        cin>>command;
        if(command=="push_front"){
            int temp;
            cin>>temp;
            myDeque.push_front(temp);
            cout<<"ok"<<endl;
        }
        if(command=="push_back"){
            int temp;
            cin>>temp;
            myDeque.push_back(temp);
            cout<<"ok"<<endl;
        }
        if(command=="pop_back"){
            myDeque.pop_back();
        }
        if(command=="pop_front"){
            myDeque.pop_front();
        }
        if(command=="front"){
            myDeque.front();
        }
        if(command=="back"){
            myDeque.back();
        }
        if(command=="size")
            cout<<myDeque.size()<<endl;
        if(command=="clear"){
            myDeque.clear();
            cout<<"ok"<<endl;
        }
        if(command=="exit"){
            cout<<"bye";
            return 0;
        }
    }
}