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
struct deque{
    private:
        int deque_size;
        node* head;
        node* tail;
    public:
        deque(){
            head=NULL;
            tail=NULL;
            deque_size=0;
        }
        void push_back(int temp){
            node* item=new node(temp);
            deque_size++;
            if(head==NULL)
                head=tail=item;
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
                head=tail=item;
            else{
                item->next=head;
                head->prev=item;
                head=item;
            }
        }
        void pop_back(){
            if(tail==NULL)
                return;
            else if(tail==head){
                head=tail=NULL;
                deque_size--;
            }else{
                tail=tail->prev;
                tail->next=NULL;
                deque_size--;
            }
        }
        void pop_front(){
            if(head==NULL){
                return;
            }
            else if(tail==head){
                tail=head=NULL;
                deque_size--;
            }
            else if(head!=NULL){
                head=head->next;
                head->prev=NULL;
                deque_size--;
            }
        }
        int front(){
            if(head==NULL)
                return -1;
            else
                return head->value;
        }
        int back(){
            if(tail==NULL)
                return -1;
            else
                return tail->value;
        }
        int size(){
            return deque_size;
        }
        bool empty(){
            return deque_size==0;
        }
        void clear(){
            while(!empty())
                pop_back();
        }

};