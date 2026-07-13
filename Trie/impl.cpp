#include <iostream>
#include <vector>
#include<string>

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

    TrieNode* children[26];
    bool isleaf;

    TrieNode(){
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        isleaf = false;
    }


    void insert(TrieNode* root ,string& word){
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


    bool search(TrieNode* root,string& word){
        TrieNode* curr = root;

        for(auto& key : word){
            int index = key - 'a';
            if(curr->children[index] == NULL){
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isleaf;
    }

    bool isprefix(TrieNode* root,string& prefix){
        TrieNode* curr = root;

        for(auto& key :prefix){
            int index = key - 'a';

            if(curr->children[index] == NULL){
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }

    bool isempty(TrieNode* root){
        for(int i = 0;i<26;i++){
            if(root->children[i] != NULL){
                return false;
            }
        }
        return true;
    }



    TrieNode* remove(TrieNode* root,string& word,int depth = 0){
        if(root == NULL){
            return NULL;
        }

        if(depth == word.size()){
            if(root->isleaf){
                root->isleaf = false;
            }

            if(isempty(root)){
                delete root;
                root = NULL;
            }
            return root;
        }

        int index = word[depth] - 'a';
        root->children[index] = remove(root->children[index],word,depth+1);

        if(isempty(root) && root->isleaf == false){
            delete root;
            root = NULL;
        }
        return root;
    }

    
};

int main(){
    TrieNode* root = new TrieNode();
    string word = "hello";
    root->insert(root,word);
    
    string searchword = "hello";
    if(root->search(root,searchword)){
        cout<<"Word found"<<endl;
    }else{
        cout<<"Word not found"<<endl;
    }
  
    string prefix = "ha";
    if(root->isprefix(root,prefix)){
        cout<<"Prefix found"<<endl;
    }else{
        cout<<"Prefix not found"<<endl;
    }

}