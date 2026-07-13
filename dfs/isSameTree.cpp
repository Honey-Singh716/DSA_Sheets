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


bool dfs(TreeNode* p,TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    if(p == NULL || q == NULL){
        return false;
    }

    if(p->val != q->val){
        return false;
    }


    return dfs(p->left,q->left) && dfs(p->right,q->right);
}

int main(){
    // Creating two sample binary trees
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(5); 

    bool result = dfs(root1, root2);
    cout << "Are the two trees the same? " << (result ? "Yes" : "No") << endl;

    return 0;
}