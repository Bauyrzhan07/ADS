#include<iostream>
#include<vector>
using namespace std;
struct heap{
    int size;
    vector<int>elements;
    heap(){
        size=0;
    }
    void sift_up(int i){
        while(i>0&&elements[(i-1)/2]<elements[i]){
            swap(elements[(i-1)/2],elements[i]);
            i=(i-1)/2;
        }
    }
    void sift_down(int i){
        if(2*i+1>size-1){
            cout<<i+1<<"\n";
            return;
        }
        int maxChildIndex=2*i+1;
        if(2*i+2<size)
            if(elements[maxChildIndex]<elements[2*i+2])
                maxChildIndex=2*i+2;
        if(elements[i]>elements[maxChildIndex]){
            cout<<i+1<<'\n';
            return;
        }
        if(elements[i]<elements[maxChildIndex]){
            swap(elements[i],elements[maxChildIndex]);
            sift_down(maxChildIndex);
        }
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
    cin>>n;
    heap* myHeap=new heap();
    for(int i=0;i<n;i++){
        cin>>temp;
        myHeap->insert(temp);
    }
    cin>>q;
    while(q--){
        int i,x;
        cin>>i>>x;
        myHeap->elements[i-1]-=x;
        myHeap->sift_down(i-1);
    }
    myHeap->print();
    return 0;
}