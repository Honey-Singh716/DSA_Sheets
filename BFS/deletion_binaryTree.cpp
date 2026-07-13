#include<iostream>
#include <queue>

using namespace std;

class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int key){
        left = NULL;
        right =  NULL;
        val = key;
    }
};


void delnode(TreeNode* root, TreeNode* node){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp == node){
            temp = NULL;
            delete(node);
            return;
        }

        if(temp->left){
            if(temp->left == node){
                temp->left = NULL;
                delete(node);
                return;

            }
            q.push(temp->left);
        }
        if(temp->right){
            if(temp->right == node){
                temp->right = NULL;
                delete(node);
                return;

            }
            q.push(temp->right);
        }
    }
}


void findDeep(TreeNode* root,int key){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        if(root->val == key){
            root = NULL;
            delete(root);
            return;
        }
    }

    queue<TreeNode*> q;
    q.push(root);

    TreeNode* keyNode;
    TreeNode*  node;
    while(!q.empty()){
       
        node = q.front();
        q.pop();

        if(node->val == key){
            keyNode = node;
        }

        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }
    
    if(keyNode != NULL){
        keyNode->val = node->val;
    }


    delnode(root,node);

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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int key = 2;
    findDeep(root,key);

    inorder(root);

    return 0;
}