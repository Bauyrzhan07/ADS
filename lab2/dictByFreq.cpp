#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    string word;
    int val;
    node* next;
    node(string w){
        word=w;
        val=1;
        next=NULL;
    }
};

bool comp(pair<string,int> a,pair<string,int> b){
    if(a.second!=b.second)
        return a.second>b.second;
    else
        return a.first<b.first;
}


struct linkedL{
    private:
    node* head;
    node* tail;
    public:
    linkedL(){
        head=tail=NULL;
    }
    void push(string w){
        if(head==NULL){
            node* newNode=new node(w);
            head=tail=newNode;
        }else if(find(w)!=NULL){
            find(w)->val++;
        }
        else{
            node* newNode=new node(w);
            tail->next=newNode;
            tail=newNode;
        }
    }
    node* find(string w){
        node* temp=head;
        while(temp!=NULL){
            if(temp->word==w)
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    void getValues(){
        ofstream outF;
        outF.open("output.txt");
        node* temp=head;
        vector<pair<string,int>>result;
        while(temp!=NULL){
            result.push_back(make_pair(temp->word,temp->val));
            temp=temp->next;
        }
        sort(result.begin(),result.end(),comp);
        for(auto it:result)
            outF<<it.first<<" "<<it.second<<endl;
        outF.close();
    }
};



int main(){
    ifstream inF;
    inF.open("input.txt");
    string temp;
    linkedL ll;
    while(inF>>temp){
        ll.push(temp);
    }
    inF.close();
    ll.getValues();
    return 0;
}