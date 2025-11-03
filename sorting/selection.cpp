#include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallestidx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallestidx]){
                smallestidx = j;
            }
        }
        swap(arr[i],arr[smallestidx]);
    }
}
int main(){
int n =5;
int arr[n] = {2,3,1,4,5};
selectionsort(arr,n);
}