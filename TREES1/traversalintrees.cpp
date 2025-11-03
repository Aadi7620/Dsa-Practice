#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
    void preorder(Node*root){
        if (root == NULL){
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node*root){
        if (root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void postorder(Node*root){
        if(root == NULL){
            return ;
            
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};
int main (){
    Node*root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    cout<<"Preorder traversal: ";
    root->preorder(root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    root->inorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    root->postorder(root);
    cout<<endl;
    return 0;
}