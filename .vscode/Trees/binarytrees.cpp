// It is a generic tree main node of the tree is root node and the data is stored in the multiple nodes the nodes are connected by branches
// top node is the root node , Leaf node is node that do not have any child node
// Building a binary tree
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
static int idx = -1;
Node*buildTree(vector<int> preorder){
    idx ++;
    if(preorder[idx] == -1) return NULL;
    Node*root = new Node(preorder[idx]);
   root->left =  buildTree(preorder);
   root->right = buildTree(preorder);
   return root;
}
int main(){
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node*root = buildTree(preorder);
    cout << root->data << endl;
    return 0;
}