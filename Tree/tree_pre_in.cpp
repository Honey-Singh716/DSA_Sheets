#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};


int preindex = 0;
TreeNode* dfs(vector<int>& preorder,int start,int end,unordered_map<int,int> mp){
    
    if(start > end){
        return NULL;
    }

    int rootval = preorder[preindex++];

    TreeNode* root = new TreeNode(rootval);

    int index = mp[rootval];

    root->left = dfs(preorder,start,index-1,mp);
    root->right = dfs(preorder,index+1,end,mp);

    return root;

}


void traversal(TreeNode* root){
    if(root == NULL){
        return;
    }

    cout<<root->val<<endl;
    traversal(root->left);
    traversal(root->right);
}

int main(){
    
    vector<int> preorder = {10,8,7,9,12,11,13};
    vector<int> inorder = {7,8,9,10,11,12,13};

    unordered_map<int,int> mp;

    for(int i =0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }

    TreeNode* root = dfs(preorder,0,preorder.size()-1,mp);
     
    traversal(root);
}