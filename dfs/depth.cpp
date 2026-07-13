#include<iostream>
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


int dfs(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(dfs(root->left),dfs(root->right));
}

int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = dfs(root);
    cout << "Height of the tree: " << height << endl;

    return 0;
}