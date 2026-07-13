#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};


void dfs(TreeNode* root){
    if(root == NULL){
        return;
    }

    dfs(root->left);
    cout<<root->val<<" ";
    dfs(root->right);
}

int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "In-order Traversal: ";
    dfs(root);
    cout << endl;

    return 0;
}