#include<iostream>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
struct bst{
private:
    node* root=NULL;
    int sz=0;
    node* insert(node* cur,int x){
        if(find(x)){
            sz--;
            return NULL;
        }
        if(!cur) return new node(x);
        if(cur->val<x)
            cur->right=insert(cur->right,x);
        if(cur->val>x)
            cur->left=insert(cur->left,x);
        return cur;
    }
    bool find(node* cur,int x){
        if(!cur) return false;
        if(cur->val==x) return true;
        if(cur->val>x) return find(cur->left,x);
        return find(cur->right,x);
    }
    void print(node* cur){
        if(!cur)
            return;
        print(cur->left);
        cout<<cur->val<<'\n';
        print(cur->right);
    }
public:
    void insert(int x){
        sz++;
        node* res=insert(root,x);
        if(!root)
            root=res;
    }
    bool find(int x){
        return find(root,x);
    }
    void print(){
        if(!root)
            return;
        print(root->left);
        cout<<root->val<<'\n';
        print(root->right);
    }
};
int main(){
    int temp;
    bst tree;
    while(true){
        cin>>temp;
        if(temp==0)
            break;
        tree.insert(temp);
    }
    tree.print();
}