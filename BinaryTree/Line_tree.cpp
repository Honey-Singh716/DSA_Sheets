#include<iostream>
#include<queue>
using namespace std;


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

vector<TreeNode*> fun(TreeNode* root , TreeNode* sym , int side){
    queue<TreeNode*> q;
    vector<TreeNode*> ans;
    
    q.push(root);
    
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(side == 1){
            if(temp != sym && temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }

        else{
            if(temp->left){
                q.push(temp->left);
            }

            if(temp != sym && temp->right){
                q.push(temp->right);
            }
        }

        ans.push_back(temp);
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

    vector<TreeNode*> left = fun(root , root->left , 1);
    vector<TreeNode*> right = fun(root , root->left , -1);

    for(int i =0;i<left.size();i++){
        cout<<left[i]->data<<",";
    }
    cout<<endl;

    for(int i =0;i<right.size();i++){
        cout<<right[i]->data<<",";
    }
    cout<<endl;
}