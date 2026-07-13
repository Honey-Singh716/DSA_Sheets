#include <iostream>
#include <unordered_map>
using namespace std;


//Brute Force Time - O(2^N) and space O(h)

//Using Hashing time - O(n) Space - O(N)


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:
    unordered_map<TreeNode*,int> mp; 
    int rob(TreeNode* root) 
    {
        if(!root){
            return 0;
        }
        TreeNode* node = root;

        if(mp.find(root) != mp.end()){
            return mp[root];
        }   

        int take = root->val;
        (root->left)?  take += (rob(root->left->left) + rob(root->left->right)): 0;
        (root->right)? take += (rob(root->right->left) + rob(root->right->right)): 0;

        int nottake = rob(root->left) + rob(root->right);
        
        return mp[root] = max(take,nottake);
    }
};

int main(){
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(3);
    root->right->left  = new TreeNode(1);
  
    Solution sol;

    int money = sol.rob(root);
    cout<<money;
    return 0;

}