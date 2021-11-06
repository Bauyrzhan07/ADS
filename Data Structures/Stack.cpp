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
struct stack{
    private:
        int stack_size;
        node* tail;
    public:
        stack(){
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
                return;
            }else if(tail->prev==NULL){
                tail=NULL;
                stack_size--;
            }else if(tail!=NULL){
                tail=tail->prev;
                tail->next=NULL;
                stack_size--;
            }
        }
        int back(){
            if(tail==NULL)
                return -1;
            else
                return tail->value;
        }
        int size(){
            return stack_size;
        }
        bool empty(){
            return stack_size==0;
        }
        void clear(){
            while(!empty()){
                pop();
            }
        }
};