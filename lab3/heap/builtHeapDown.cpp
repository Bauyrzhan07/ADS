#include<iostream>
#include<vector>
using namespace std;
struct heap{
private:
    int size;
    vector<int>elements;
public:
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
            return;
        }
        int maxChildIndex=2*i+1;
        if(2*i+2<size)
            if(elements[maxChildIndex]<elements[2*i+2])
                maxChildIndex=2*i+2;
        if(elements[i]>elements[maxChildIndex]){
            return;
        }
        if(elements[i]<elements[maxChildIndex]){
            swap(elements[i],elements[maxChildIndex]);
            sift_down(maxChildIndex);
        }
    }
    void del(int i){
        swap(elements[i],elements[0]);
        extractMax();
    }
    void builtHeapDown(){
        for(int i=size/2;i>=0;i--)
            sift_down(i);
    }
    void insert(int x){
        size++;
        elements.push_back(x);
    }
    int extractMax(){
        int min=elements[0];
        swap(elements[0],elements[size-1]);
        size--;
        sift_down(0);
        return min;
    }
    void print(){
        for(int i=0;i<size;i++)
            cout<<elements[i]<<" ";
        cout<<endl;
    }
};
int main(){
    int n,temp;
    cin>>n;
    heap* myHeap=new heap();
    for(int i=0;i<n;i++){
        cin>>temp;
        myHeap->insert(temp);
    }
    myHeap->builtHeapDown();
    myHeap->print();
    return 0;
}