#include<iostream>
using namespace std;
class node{
public:
int data;
node*next;
node(int val){
    data = val;
    next = NULL;
}
};
class Queue {
node*head;
node*tail;
public:
Queue(){
    head = tail = NULL;
}
void push(int val){
node*newnode = new node(val);
if(head == NULL){
    head = tail = newnode;
}else{
    tail->next = newnode;
    tail = newnode;
}
}
void pop(){
    if(head == NULL){
        cout<<"list is empty";
        return;
    }else{
        node*temp = head;
        head = head->next;
delete temp;
    }
}
int front(){
    if(head == NULL){
        cout<<"list is empty";
        return -1;
    }else{
        return head->data;
    }
}
bool empty(){
    return head == NULL;
}
};
int main (){
    Queue aa;
    aa.push(10);
    aa.push(20);
    aa.push(30);
    while(!aa.empty()){
        cout<<aa.front()<<endl;
        aa.pop();
    }
    cout<<endl;
    return 0;
}