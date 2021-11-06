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
struct queue{
    private:
        int queue_size;
        node* head;
        node* tail;
    public:
        queue(){
            head=NULL;
            tail=NULL;
            queue_size=0;
        }
        void push(int temp){
            node* item=new node(temp);
            queue_size++;
            if(head==NULL){
                head=tail=item;
            }else{
                item->prev=tail;
                tail->next=item;
                tail=item;
            }
        }
        void pop(){
            if(head==NULL){
                return;
            }else if(head->next==tail){
                head=tail;
                queue_size--;
            }else if(head->next==NULL){
                head=tail=NULL;
                queue_size--;
            }else if(head!=NULL){
                head=head->next;
                head->prev=NULL;
                queue_size--;
            }
        }
        int front(){
            if(head==NULL)
                return -1;
            else
                return head->value;
        }
        int size(){
            return queue_size;
        }
        bool empty(){
            return queue_size==0;
        }
        void clear(){
            while(!empty())
                pop();
        }

};