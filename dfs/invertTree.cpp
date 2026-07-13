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

void dfs(TreeNode* root){
    if(root == NULL){
        return;
    }

    swap(root->left,root->right);
    dfs(root->left);
    dfs(root->right);
}

void inorder(TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original Tree (In-order Traversal): ";
    inorder(root); // In-order traversal before inversion
    cout << endl;

    dfs(root); // Invert the tree

    cout << "Inverted Tree (In-order Traversal): ";
    inorder(root); // In-order traversal after inversion
    cout << endl;

    return 0;
}