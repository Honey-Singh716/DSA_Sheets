#include <iostream>
#include<queue>
#include<vector>

using namespace std;

class Node{
    public:

    int data;
    Node* next;


    Node(int x){
        data = x;
        next = NULL;
    }
};


class TreeNode{
    public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i =0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}


int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = levelOrder(root);

    for(int i =0;i<ans.size();i++){
        for(int j =0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}