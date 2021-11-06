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
    void insert(int x){
        size++;
        elements.push_back(x);
        int i=size-1;
        sift_up(i);
    }
    int extractMax(){
        int max=elements[0];
        swap(elements[0],elements[size-1]);
        elements.pop_back();
        size--;
        sift_down(0);
        return max;
    }
    void print(){
        for(int i=0;i<size;i++)
            cout<<elements[i]<<" ";
        cout<<endl;
    }
};
int main(){
    int n,command,temp;
    cin>>n;
    heap* myHeap=new heap();
    while(n--){
        cin>>command;
        if(command==0){
            cin>>temp;
            myHeap->insert(temp);
        }else if(command==1){
            cout<<myHeap->extractMax()<<'\n';
        }else if(command==2)
            myHeap->print();
    }
    return 0;
}