#include<iostream>
#include<vector>
using namespace std;
struct MinHeap{
private:
    int size;
    vector<int>elements;
public:
    MinHeap(){
        size=0;
    }
    void sift_up(int i){
        while(i>0&&elements[(i-1)/2]>elements[i]){
            swap(elements[(i-1)/2],elements[i]);
            i=(i-1)/2;
        }
    }
    void sift_down(int i){
        if(2*i+1>size-1){
            return;
        }
        int minChildIndex=2*i+1;
        if(2*i+2<size)
            if(elements[minChildIndex]>elements[2*i+2])
                minChildIndex=2*i+2;
        if(elements[i]<elements[minChildIndex]){
            return;
        }
        if(elements[i]>elements[minChildIndex]){
            swap(elements[i],elements[minChildIndex]);
            sift_down(minChildIndex);
        }
    }
    void del(int i){
        swap(elements[i],elements[0]);
        extractMin();
    }
    void insert(int x){
        size++;
        elements.push_back(x);
        int i=size-1;
        sift_up(i);
    }
    int extractMin(){
        int min=elements[0];
        swap(elements[0],elements[size-1]);
        elements.pop_back();
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