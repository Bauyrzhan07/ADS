#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int val;
    node* next;
    node* prev;
    node(int x){
        val=x;
        next=NULL;
        prev=NULL;
    }
};
struct linkedL{
    private:
    node* head;
    node* tail;
    public:
    bool error=false;
    linkedL(){
        head=tail=NULL;
    }
    void push(int x){
        node* newNode=new node(x);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void pop(int x){
        node* dlElem=find(x);
        if(dlElem==NULL){
            ofstream outF;
            outF.open("output.txt");
            outF<<"ERROR"<<endl;
            error=true;
        }
        else if(dlElem->next==NULL&&dlElem->prev==NULL){
            head=tail=dlElem=NULL;
        }
        else if(dlElem==head){
            dlElem=NULL;
            head=head->next;
            head->prev=NULL;
        }
        else if(dlElem==tail){
            dlElem=NULL;
            tail=tail->prev;
            tail->next=NULL;
        }else{        
            dlElem->prev->next=dlElem->next;
            dlElem->next->prev=dlElem->prev;
            dlElem=NULL;
        }
    }
    node* find(int x){
        node* temp=head;
        while(temp!=NULL){
            if(temp->val==x)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    void print(){
        ofstream outF;
        outF.open("output.txt");
        vector<int>res;
        node* temp=head;
        if(head==NULL)
            outF<<"EMPTY";
        else{
            while(temp!=NULL){
                res.push_back(temp->val);
                temp=temp->next;
            }
            sort(res.begin(),res.end());
            for(auto it:res)
                outF<<it<<" ";
        }
    }
};
int main(){
    ifstream inF;
    
    inF.open("input.txt");
    
    linkedL ll;
    string command;
    int x;
    while(inF>>command){
        x=stoi(command.substr(1,command.size()-1));
        if(command[0]=='+'){
            ll.push(x);
        }else if(command[0]=='-'){
            ll.pop(x);
            if(ll.error)
                return 0;
        }
    }
    ll.print();
    return 0;
}