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
    int getSize(){
        return size;
    }
    int sift_up(int i){
        while(i>0&&elements[(i-1)/2]<elements[i]){
            swap(elements[(i-1)/2],elements[i]);
            i=(i-1)/2;
        }
        return i;
    }
    int sift_down(int i){
        int result;
        if(2*i+1>size-1){
            return i+1;
        }
        int maxChildIndex=2*i+1;
        if(2*i+2<size)
            if(elements[maxChildIndex]<elements[2*i+2])
                maxChildIndex=2*i+2;
        if(elements[i]>elements[maxChildIndex]){
            return i+1;
        }
        if(elements[i]<elements[maxChildIndex]){
            swap(elements[i],elements[maxChildIndex]);
            result=sift_down(maxChildIndex);
        }
        return result;
    }
    void insert(int x){
        size++;
        elements.push_back(x);
        int i=size-1;
        cout<<sift_up(i)+1<<'\n';
    }
    void extractMax(){
        int min=elements[0];
        if(size==1){
            size--;
            cout<<0<<" "<<min<<'\n';
            elements.pop_back();
            return;
        }
        swap(elements[0],elements[size-1]);
        size--;
        int result=sift_down(0);
        cout<<result<<" "<<min<<'\n';
        elements.pop_back();
    }
    bool empty(){
        return size==0;
    }
    void print(){
        for(int i=0;i<size;i++)
            cout<<elements[i]<<" ";
        cout<<endl;
    }
};
int main(){
    int n,m,command,temp;
    cin>>n>>m;
    heap myHeap;
    while(m--){
        cin>>command;
        if(command==1){
            if(myHeap.empty()){
                cout<<-1<<'\n';
                continue;
            }
            myHeap.extractMax();
        }
        if(command==2){
            cin>>temp;
            if(myHeap.getSize()==n){
                cout<<-1<<'\n';
                continue;
            }
            myHeap.insert(temp);
        }
    }
    myHeap.print();
}