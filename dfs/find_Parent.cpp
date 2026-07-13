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


void dfs(TreeNode* root,TreeNode* parent,TreeNode* target,TreeNode* & ans){
    if(root == NULL){
        return;
    }

    if(root == target){
        ans = parent;
        return;
    }

    dfs(root->left,root,target,ans);
    dfs(root->right,root,target,ans);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* target = root->left->right; // Target node (value 2)
    TreeNode* ans = NULL;

    dfs(root, NULL, target, ans);

    if(ans){
        cout << "Parent of node " << target->val << " is: " << ans->val << endl;
    } else {
        cout << "Target node is the root or not found." << endl;
    }

    return 0;
}