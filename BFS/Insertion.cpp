#include<iostream>
#include<queue>

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

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    
}


void insertion(TreeNode* root,int key){
    if(root  == NULL){
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if(node->left == NULL){
            node->left = new TreeNode(key);
            return;
        }
        if(node->right == NULL){
            node->right = new TreeNode(key);
            return;
        }

        q.push(node->left);
        q.push(node->right);
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int key = 5;
    insertion(root,key);

    inorder(root);

    return 0;
}