
class Solution {
public:
   int preindex = 0;
   unordered_map<int,int> mp;
   TreeNode* dfs(int start,int end,vector<int>& preorder){
        if(start > end){
            return NULL;
        }

        int rootval = preorder[preindex++];

        TreeNode* root = new TreeNode(rootval);
          
        if(start == end){
            return root;
        }

        if(preindex >= preorder.size()){
            return root;
        }  

        int leftval = preorder[preindex];
        int leftindex = mp[leftval];
       

        root->left = dfs(start,leftindex,preorder);
        root->right = dfs(leftindex + 1,end-1,preorder);  

        return root;
   }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      

        for(int i =0;i<postorder.size();i++){
            mp[postorder[i]] = i;
        }

        TreeNode* root =  dfs(0,postorder.size()-1,preorder);

        return root;
    }
};