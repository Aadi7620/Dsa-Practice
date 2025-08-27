#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class list{
node*head;
node*tail;
public:
list(){
    head = tail = NULL;
}
void push_front(int val){
    node*newnode = new node(val);
    if(head == NULL){
        head = tail = newnode;
        return;
    }else{
        newnode->next = head;
        head = newnode;
        return;
    }
}
void push_back(int val){
    node*newnode = new node(val);
    if(head == NULL){
        head = tail = newnode;
        return;
    }else{
        tail->next = newnode;
        tail = newnode;
        return;
    }
}
void pop_front(){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }else{
        node*temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
}
void pop_back(){
    if(head == NULL){
        cout<<"list is empty";
        return;
    }else{
        node*temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }
}
void insert(int val, int pos){
    if(pos<0){
        cout<<"invalid";
        return;
    }
    if(pos == 0){
        push_front(val);
        return;
    }
    node*temp = head;
    for(int i = 0;i<pos-1;i++){
         temp = temp->next;
    }
    node*newnode = new node(val);
    newnode->next = temp->next;
    temp->next = newnode;
}
void printLL(){
    node*temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void swapnodes(){
    node*first = head;
    node*second = head->next;
    node*prev = NULL;
    while(first != NULL && second != NULL){
        node*third = second->next;
        second->next = first;
        first->next = third;
        if(prev != NULL){
            prev->next = NULL;
        }else{
            head = second;
        }
        prev = first;
        first = third;
        if(third != NULL){
            second = third->next;
        }else{
            second = NULL;
        }
    }
}
};


int main(){
    list l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.insert(4,2);
    l.pop_back();
    l.pop_front();
    l.printLL();
    l.swapnodes();
    l.printLL();
    return 0;
}