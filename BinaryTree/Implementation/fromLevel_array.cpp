#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};



TreeNode* build(vector<int> arr){
    if(arr.size() == 0){
        return NULL;
    }

    TreeNode* root = new TreeNode(arr[0]);
    queue<pair<TreeNode*,int>> q;


    q.push({root, 0});

    while(!q.empty()){
        auto [node, index] = q.front();
        q.pop();

        int leftIndex = 2*index + 1;
        int rightIndex = 2*index + 2;

        node->left = (leftIndex<arr.size()) ? new TreeNode(arr[leftIndex]) : NULL;
        node->right = (rightIndex<arr.size()) ? new TreeNode(arr[rightIndex]) : NULL;

        if(node->left){
            q.push({node->left, 2*index + 1});
        }
        if(node->right){
            q.push({node->right, 2*index + 2});
        }
    }
    return root;
}


void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    TreeNode* root = build(arr);
    
    inorder(root);
   
    return 0;
}