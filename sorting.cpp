#include <bits/stdc++.h>
using namespace std;
int findPiv(vector<int> &arr,int s,int e){
    int cnt=0;
    int pivot=arr[s];
    for(int i=s;i<=e;i++){
        if(arr[i]<pivot){
            cnt++;
        }
    }
    int piv=s+cnt;
    swap(arr[s],arr[piv]);
    int i=s;
    int j=e;
    while(i<piv && j>piv){
        while(arr[i]<=arr[piv]){
            i++;
        }
        while(arr[j]>arr[piv]){
            j--;
        }
        if(i<piv && j>piv){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
    }
    return piv;
}
void quickSort(vector<int> &arr,int s,int e){
    if(s>=e){
        return ;
    }
    int pivIdx=findPiv(arr,s,e);
    quickSort(arr,s,pivIdx-1);
    quickSort(arr,pivIdx+1,e);
}
void merge(vector<int> &arr,int s,int mid,int e){
    vector<int> temp(e-s+1);
    int i=s;
    int j=mid+1;
    int idx=0;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[idx]=arr[i];
            idx++;
            i++;
        }
        else if(arr[j]<arr[i]){
            temp[idx]=arr[j];
            j++;
            idx++;
        }
    }
    while(i<=mid){
        temp[idx]=arr[i];
        i++;
    }
    while(j<=e){
        temp[idx]=arr[j];
        j++;
    }
    int id=s;
    for(auto it:temp){
        arr[id]=it;
        id++;
    }

}
void mergeSort(vector<int> &arr,int s,int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
void insertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;  
        }
        arr[j+1]=temp;
    }
}
void bubbleSort(vector<int> &arr){
    // swap adjacent elements
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void selectionSort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main() {
    vector<int> arr={8,1,3,10,6};
    int e=arr.size()-1;
    insertionSort(arr);
    for(auto it:arr){
        cout<<it<<",";
    }

}
