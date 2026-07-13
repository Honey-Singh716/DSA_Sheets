#include <iostream>
#include <vector>
#include <queue>
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


vector<vector<int>> verticalTraversal(TreeNode* root){
    
    if(root == NULL){
        return {};
    }
    
    queue<pair<int,TreeNode*>> q;
    q.push({0,root});
    priority_queue<pair<int,TreeNode*>,vector<pair<int,TreeNode*>>,greater<pair<int,TreeNode*>>> pq;

    while(!q.empty()){
        int size = q.size();

        for(int i =1;i<=size;i++){
            auto [p,node] = q.front();
            q.pop();
            pq.push({p,node});

            if(node->left){
                q.push({p-1,node->left});
            }

            if(node->right)
              q.push({p+1,node->right});
        }
    }
    
    vector<vector<int>> ans;
    while(!pq.empty()){
        auto [p,node] = pq.top();
        pq.pop();
        
        ans[p+1000].push_back(node->val);
        
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

    vector<vector<int>> result = verticalTraversal(root);

    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}