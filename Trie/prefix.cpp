#include <iostream>
#include <vector>

#include <string>

using namespace std;

class TreeNode{
    public:
    char data;

    vector<TreeNode*> children;

    TreeNode(char data){
        this->data = data;
    }
};

class TrieNode{
    public:
    bool isleaf;
    TrieNode* children[26];

    TrieNode(){
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        isleaf = false;
    }

    void insert(TrieNode* root ,string word){
        TrieNode* curr = root;

        for(auto& key : word){
            int index = key - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isleaf = true;
    }


    int prefix(TrieNode* root,string& prefix){
        TrieNode* curr = root;

        for(auto& key : prefix){
            int index = key - 'a';

            if(curr->children[index] == NULL){
                break;
            }
            curr = curr->children[index];
        }

        int count = 0;
        for(int i =0;i<26;i++){
            if(curr->children[i] != NULL){
                count++;
            }
        }        
        return count;
    }




};


int main(){
    
    TrieNode* root = new TrieNode();
    
    root->insert(root,"hello");
    root->insert(root,"henry");
    root->insert(root,"hennah");

  
    string prefix = "he";
    
    cout<<root->prefix(root,prefix)<<endl;

    return 0;
}