#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;

    int val;

    TreeNode(int d): val(d),left(nullptr),right(nullptr){}
};

TreeNode* dfs(int& preindex,vector<int> &postorder,int start,int end,unordered_map<int,int>& mp){
    if(start > end) return NULL;

    int rootval = postorder[preindex--];

    TreeNode* root = new TreeNode(rootval);

    int index  =  mp[rootval];

    root->right = dfs(preindex,postorder,index+1,end,mp);
    root->left = dfs(preindex,postorder,start,index-1,mp);
    return root;
}

void traversal(TreeNode* root){
    if(root == NULL) return;

    traversal(root->left);
    traversal(root->right);
    cout<<root->val<<" ";
}


int main(){
    vector<int> postorder = {11,8,13,9,12,10,7};
    vector<int> inorder = {11,8,13,9,12,7,10};


    unordered_map<int,int> mp;

    for(int i = 0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }

    int preindex = postorder.size() - 1;
    TreeNode* root = dfs(preindex, postorder, 0, inorder.size() - 1, mp);
    traversal(root);
}
