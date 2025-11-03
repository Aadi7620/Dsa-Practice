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
bool issubtree(Node*maintree , Node*subtree){
    if(subtree == NULL){
return true;
    }
    if(maintree == NULL){
        return false;
    }
    if(identicaltrees(maintree ,subtree)){
        return true;
    }
    return issubtree(maintree->left , subtree) || issubtree(maintree->right , subtree);
}
int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    Node* root2 = new Node(2);
    root2->left = new Node(4);
    root2->right = new Node(5);
    if(issubtree(root1, root2)){
        cout<<"Tree2 is a subtree of Tree1"<<endl;
    }
    else{
        cout<<"Tree2 is not a subtree of Tree1"<<endl;
    }
    return 0;
}