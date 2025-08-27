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
class stack{
    public:
    node*head = NULL;
    void push(int val){
        node*newnode = new node(val);
        newnode->next =  head;
        head = newnode;  
     }
     void pop(){
        if(head == NULL){
            cout<<"stack is empty"<<endl;
            return;
        }
        node*temp = head;
        head = head->next;
        delete temp;
    }
    void print(){
        node*temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

};
int main(){
    stack aa;
    aa.push(20);
    aa.push(30);
    aa.push(40);
    aa.print();
    aa.pop();
    aa.print();

}