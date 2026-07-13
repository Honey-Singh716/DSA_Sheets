#include<iostream>
#include<vector>
#include<unordered_map>

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

void diagonalTraversal(TreeNode* root,int level,unordered_map<int,vector<int>>& mp){
    if(root == NULL){
        return;
    }
    mp[level].push_back(root->val);
    diagonalTraversal(root->left,level+1,mp);
    diagonalTraversal(root->right,level,mp);
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> ans;

    unordered_map<int,vector<int>>mp;

    diagonalTraversal(root,0,mp);

    for(auto it : mp){
        ans.push_back(it.second);
    }

    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}