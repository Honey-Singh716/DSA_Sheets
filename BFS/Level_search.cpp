#include<iostream>
#include <queue>
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



int level(TreeNode* root,int target){
    if(root == NULL){
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()){
        int size = q.size();

        level++;
        while(size--){
            TreeNode* node = q.front();
             q.pop();

             if(node->val == target){
                return level;
             }

             if(node->left){
                q.push(node->left);
             }
             if(node->right){
                q.push(node->right);
             }
            }
    }
    return -1;
}

int main(){
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int target = 5;
    int result = level(root, target);
    if(result != -1){
        cout << "Level of node with value " << target << ": " << result << endl;
    } else {
        cout << "Node with value " << target << " not found in the tree." << endl;
    }

    return 0;
}