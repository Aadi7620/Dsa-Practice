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
int heightoftree(Node*root){
    if(root == NULL){
        return 0;
    }
    int leftheight = heightoftree(root->left);
    int rightheight = heightoftree(root->right);
    return max(leftheight, rightheight) + 1;

}
int main (){
    vector<int> preorder = {1 , 2 , -1 ,-1,3,4,-1,-1,5,-1,-1};
    Node*root = buildTree(preorder);
    cout<<heightoftree(root)<<endl;
    return 0;
}