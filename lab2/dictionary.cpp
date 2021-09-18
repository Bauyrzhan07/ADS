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
        node* result=NULL;
        node* temp=head;
        while(temp!=NULL){
            if(temp->word==w){
                result=temp;
                break;
            }
            temp=temp->next;
        }
        return result;
    }
    vector<pair<string,int>> getValues(){
        node* temp=head;
        vector<pair<string,int>> result;
        while(temp!=NULL){
            result.push_back(make_pair(temp->word,temp->val));
            temp=temp->next;
        }
        return result;
    }
};

bool comp(pair<string,int> a,pair<string,int> b){
    return a.first<b.first;
}

int main(){
    ofstream outF;
    ifstream inF;
    inF.open("input.txt");
    outF.open("output.txt");
    string temp;
    linkedL ll;
    while(inF>>temp){
        ll.push(temp);
    }
    vector<pair<string,int>> result;
    result=ll.getValues();
    sort(result.begin(),result.end(),comp);
    for(auto it:result)
        outF<<it.first<<" "<<it.second<<endl;
    outF.close();
    return 0;
}