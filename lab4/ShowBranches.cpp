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
    int getMaxHeight(node* cur){
        if(!cur)
            return 0;
        return max(getMaxHeight(cur->left),getMaxHeight(cur->right))+1;
    }
    int getMax(node* cur){
        if(!cur->right)
            return cur->val;
        return getMax(cur->right);
    }
    node* getMaxNode(node* cur){
        if(!cur->right){
            return cur;
        }
        return getMaxNode(cur->right);
    }
    node* del(node* cur,int x){
        if(!cur)
            return NULL;
        if(cur->val>x){
            cur->left=del(cur->left,x);
        }else if(cur->val<x){
            cur->right=del(cur->right,x);
        }else{
            if(!cur->left&&!cur->right){
                delete cur;
                return NULL;
            }else if(!cur->left&&cur->right){
                node* temp=cur->right;
                delete cur;
                return temp;
            }else if(!cur->right&&cur->left){
                node* temp=cur->left;
                delete cur;
                return temp;
            }else{
                node* temp=getMaxNode(cur->left);
                cur->val=temp->val;
                cur->left=del(cur->left,temp->val);
            }
        }
    }
    void print(node* cur){
        if(!cur)
            return;
        print(cur->left);
        cout<<cur->val<<' ';
        print(cur->right);
    }
    void showBranches(node* cur){
        if(!cur)
            return;
        showBranches(cur->left);
        if(cur->left&&!cur->right)
            cout<<cur->val<<'\n';
        if(!cur->left&&cur->right)
            cout<<cur->val<<'\n';
        showBranches(cur->right);
    }
public:
    void insert(int x){
        sz++;
        root=insert(root,x);
    }
    bool find(int x){
        return find(root,x);
    }
    int getSize(){
        return sz;
    }
    int getMaxHeight(){
        if(!root)
            return 0;
        return max(getMaxHeight(root->left),getMaxHeight(root->right))+1;
    }
    int getMax(){
        if(!root->right)
            return root->val;
        return getMax(root->right);
    }
    void del(int x){
        del(root,x);
    }
    void print(){
        if(!root)
            return;
        print(root->left);
        cout<<root->val<<' ';
        print(root->right);
    }
    void showBranches(){
        if(!root)
            return;
        showBranches(root->left);
        if(root->left&&!root->right)
            cout<<root->val<<'\n';
        if(!root->left&&root->right)
            cout<<root->val<<'\n';
        showBranches(root->right);
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
    tree.showBranches();
    return 0;
}