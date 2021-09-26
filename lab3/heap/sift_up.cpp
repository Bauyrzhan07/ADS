#include<iostream>
#include<vector>
using namespace std;
struct heap{
private:

public:
    int size;
    vector<int>elements;
    heap(){
        size=0;
    }
    int sift_up(int i){
        while(i>0&&elements[(i-1)/2]<elements[i]){
            swap(elements[(i-1)/2],elements[i]);
            i=(i-1)/2;
        }
        return i+1;
    }
    void insert(int x){
        size++;
        elements.push_back(x);
        int i=size-1;
        sift_up(i);
    }
    void print(){
        for(int i=0;i<size;i++)
            cout<<elements[i]<<" ";
        cout<<endl;
    }
};
int main(){
    int n,temp,q;
    heap* myHeap=new heap();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        myHeap->insert(temp);
    }
    cin>>q;
    while(q--){
        int i,x;
        cin>>i>>x;
        myHeap->elements[i-1]+=x;
        cout<<myHeap->sift_up(i-1)<<endl;
    }
    myHeap->print();
    return 0;
}