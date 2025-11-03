#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*right;
    Node*left;
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};
bool identicaltrees(Node*root1, Node*root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    return (root1->data == root2->data) && identicaltrees(root1->left, root2->left) && identicaltrees(root1->right, root2->right);
}
int main(){
    Node*root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    Node*root2 = new Node(4);
    root2->left = new Node(5);
    root2->right = new Node(6);
    if(identicaltrees(root1, root2)){
        cout<<"Trees are identical" << endl;
        cout<<"Root1: " << root1->data << ", Root2: " << root2->data << endl;

    }
    else{
        cout<<"Trees are not identical"<<endl;
        cout<<"Root1:" <<root1->data <<", Root2: "<< root2->data <<endl;
    }
    return 0;
}