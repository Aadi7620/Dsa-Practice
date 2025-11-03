//BST is a special type of binary tree that organize data so that searching insertion and deletion can be done in a organized and quick way.
// all keys in left subtree of a node are less then the key value of the node
// all the keys in the right subtree of a node greater then the key value of the node
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int key;
    Node*left;
    Node*right;
    Node(int val){
        key = val;
        left = right = NULL;
    }
};
class BST{
    public:
    Node*root;
   
    Node*insert(Node*root,int key){
        if(root == NULL){
            return new Node(key);
        }
        if(key < root->key){
            root->left = insert(root->left,key);
        }
        else{
            root->right = insert(root->right,key);
        }
        return root;
    }
    int minvalue(Node*root){
        int minv = root->key;
        while(root->left != NULL){
            minv = root->left->key;
root = root->left;
        }
        return minv;
    }
    Node*deleteNode(Node*root,int key){
if (root == NULL){
    return root;
}
if(key < root->key){
    root->left = deleteNode(root->left,key);
}
else if (key > root->key){
    root->right = deleteNode(root->right,key);
}
else{
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }
    root->key = minvalue(root->right);
    root->right = deleteNode(root->right,root->key);
}
return root;
}
public:
BST(){
    root = NULL;
}
void insert(int key){
    root = insert(root,key);
}
void deleteNode(int key){
    root = deleteNode(root,key);
}
void inorder(Node*root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
bool search(Node*root,int key){
    if(root == NULL){
        return false;
    }
    if(root->key == key){
        return true;
    }
    if(key < root->key){
        return search(root->left,key);
    }else{
    return search(root->right,key);
    }
}
void display(){
    inorder(root);
    cout<<endl;
}
};

int main (){
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    cout<<"Inorder Traversal: ";
    bst.display();
    bst.deleteNode(3);
    cout<<"Inorder Traversal after deletion: ";
    bst.display();
    cout<<"search 5: "<<(bst.search(bst.root,5) ? "Found" : "Not Found");
    return 0;
}