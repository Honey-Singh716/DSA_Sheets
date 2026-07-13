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
    
    int sum = root->val;
    sum += dfs(root->left);
    sum += dfs(root->right);
    return sum;
}

int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int totalSum = dfs(root);
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}