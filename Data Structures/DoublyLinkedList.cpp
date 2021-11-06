#include<iostream>
using namespace std;
struct node{
    int val;
    node* prev;
    node* next;
    node(int x){
        val=x;
        prev=NULL;
        next=NULL;
    }
};
struct DoublylinkedList{
private:
    int size;
    node* head; 
    node* tail;
public:
    DoublylinkedList(){
        size=0;
        head=NULL;
        tail=NULL;
    }
    void insert(int x){
        size++;
        node* temp=new node(x);
        if(head==NULL){
            head=tail=temp;
        }else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    void del(int x){
        node* temp=head;
        while(temp->val!=x)
            temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
    void print(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    int size(){
        return size;
    }
    bool empty(){
        return size==0;
    }
    void clear(){
        head=tail=NULL;
        size=0;
    }
};