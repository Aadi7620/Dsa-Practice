//in bubble sort there are n-1 iterations , adj element are compared,larger is pushed at the last
#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j =0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n =5;
    int arr[n] = {4,1,2,5,3};
    bubblesort(arr,n);
    printarray(arr,n);
    return 0;
}