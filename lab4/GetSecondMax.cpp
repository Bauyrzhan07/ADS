#include<iostream>
#include<vector>
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
    vector<int>inorder;
    node* insert(node* cur,int x){
        if(!cur) return new node(x);
        if(cur->val<x)
            cur->right=insert(cur->right,x);
        if(cur->val>x)
            cur->left=insert(cur->left,x);
        return cur;
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
        return cur;
    }
    void in_push(node* cur){
        if(!cur)
            return;
        in_push(cur->left);
        inorder.push_back(cur->val);
        in_push(cur->right);
    }
    node* getMaxNode(node* cur){
        if(!cur->right){
            return cur;
        }
        return getMaxNode(cur->right);
    }
    int getMax(node* cur){
        if(!cur->right)
            return cur->val;
        return getMax(cur->right);
    }
    void print(node* cur){
        if(!cur)
            return;
        print(cur->left);
        cout<<cur->val<<' ';
        print(cur->right);
    }
public:
    void insert(int x){
        sz++;
        root=insert(root,x);
    }
    int getMax(){
        if(!root->right)
            return root->val;
        return getMax(root->right);
    }
    void del(int x){
        del(root,x);
    }
    void in_push(){
        if(!root)
            return;
        in_push(root->left);
        inorder.push_back(root->val);
        in_push(root->right);
    }
    int getSecondMax(){
        return inorder[sz-2];
    }
    void print(){
        if(!root)
            return;
        print(root->left);
        cout<<root->val<<' ';
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
    tree.in_push();
    cout<<tree.getSecondMax();
    return 0;
}