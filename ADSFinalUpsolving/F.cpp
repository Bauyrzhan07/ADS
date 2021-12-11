#include<iostream>
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = arr[m + 1 + i];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
using namespace std;
int main(){
    int n;cin>>n;
    int pref_sum[n+1],a[n];
    pref_sum[0] = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pref_sum[i+1] = pref_sum[i] + a[i];
    }
    int res = 1e9;
    mergeSort(pref_sum,0,n);
    for(int i=0;i<n+1;i++)
        res = min(res,abs(pref_sum[i+1]-pref_sum[i]));
    cout<<res;
    return 0;
}