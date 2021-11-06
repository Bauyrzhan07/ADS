#include<iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node(int x){
        val=x;
        next=NULL;
    }
};
struct linkedList{
private:
    int size;
    node* head; 
    node* tail;
public:
    linkedList(){
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
            tail=temp;
        }
    }
    void del(int x){
        node* temp=head;
        while(temp->next->val!=x)
            temp=temp->next;
        temp->next=temp->next->next;
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
};/*
*/