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

void dfs(TreeNode* root,int target,int level,int & ans){
    if(root == NULL){
        return;
    }


    if(root->val == target){
        ans = level;
        return;
    }

    dfs(root->left,target,level+1,ans);
    dfs(root->right,target,level+1,ans);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int target = 3;
    int ans = -1;

    dfs(root,target,0,ans);

    cout<<ans;

    return 0;
}