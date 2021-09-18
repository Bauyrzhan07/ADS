#include<iostream>
#include<fstream>
using namespace std;
struct node{
    int level;
    string val;
    node* next;
    node* prev;
    node(string x,int lvl){
        level=lvl;
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
    int lvlSize;
    linkedL(){
        head=tail=NULL;
        lvlSize=0;
    }
    void push(string text,int lvl){
        node* newNode=new node(text,lvl);
        if(head==NULL){
            head=tail=newNode;
            lvlSize++;
        }else if(lvl==1&&lvlSize==1){
            head=newNode;
            head->next=tail;
            tail->prev=head;
            tail->level++;
            lvlSize++;
        }else if(lvl<=lvlSize){
            node* temp=head;
            while(temp->level!=lvl){
                temp=temp->next;
            }
            if(temp==head){
                head->prev=newNode;
                newNode->next=head;
                head=newNode;
            }else{
                temp->prev->next=newNode;
                newNode->prev=temp->prev;
                temp->prev=newNode;
                newNode->next=temp;
            }
            while(temp!=NULL){
                temp->level++;
                temp=temp->next;
            }
            lvlSize++;
        }else if(lvl-1==lvlSize){
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            lvlSize++;
        }else{
            ofstream outF;
            outF.open("output.txt");
            outF<<"ERROR";
            error=true;
        }
    }
    void pop(int lvl){
        if(lvl>lvlSize){
            ofstream outF;
            outF.open("output.txt");
            error=true;
            outF<<"ERROR";
        }
        else{
            node* temp=head;
            while(temp->level!=lvl){
                temp=temp->next;
            }
            if(temp->next==NULL&&temp->prev==NULL){
                head=tail=NULL;
            }
            else if(temp==head){
                head=head->next;
                head->prev=NULL;
                temp=head;
                while(temp!=NULL){
                    temp->level--;
                    temp=temp->next;
                }
            }
            else if(temp==tail){
                tail=temp->prev;
                tail->next=NULL;
                temp=NULL;
            }else{
                node* nextNode=temp->next;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                temp=NULL;
                while(nextNode!=NULL){
                    nextNode->level--;
                    nextNode=nextNode->next;
                }
            }
            lvlSize--;
        }

    }
    void replace(string text,int lvl){
        if(lvl>lvlSize){
            ofstream outF;
            outF.open("output.txt");
            error=true;
            outF<<"ERROR";
        }else{
            node* temp=head;
            while(temp->level!=lvl){
                temp=temp->next;
            }
            temp->val=text;
        }
    }
    void print(){
        ofstream outF;
        outF.open("output.txt");
        node* temp=head;
        if(head==NULL)
            outF<<"EMPTY"<<endl;
        else{
            while(temp!=NULL){
                outF<<temp->val<<endl;
                temp=temp->next;
            }
        }
    }
};
int main(){
    ifstream inF;
    inF.open("input.txt");
    linkedL ll;
    string command;
    int lvl;
    while(getline(inF,command)){
        lvl=stoi(command.substr(1,3));
        if(command[0]=='+'){
            command.erase(0,3);
            ll.push(command,lvl);    
        }else if(command[0]=='*'){
            command.erase(0,3);
            ll.replace(command,lvl);
        }else if(command[0]=='-')
            ll.pop(lvl);
        if(ll.error)
            return 0;
    }
    ll.print();
    return 0;
}