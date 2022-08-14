#include <bits/stdc++.h>

using namespace std;

class Node{
    private:
        int data;

    public:
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        ~Node(){
            delete this->left;
            delete this->right;
        }

        int getData(){
            return this->data;
        }
};

class BinaryTree{
    Node* createBTPreorderPiv(vector<int> preorder, vector<int> inorder, 
                           int start, int end, unordered_map<int, int> idxMap){
        
        static int idx=0;
        if(start>end){
            return NULL;
        }

        int curr = preorder[idx++];
        Node* root = new Node(curr);

        if(start == end){
            return root;
        }

        int inIdx = idxMap[curr];

        root->left = createBTPreorderPiv(preorder, inorder, start, inIdx-1, idxMap);
        root->right = createBTPreorderPiv(preorder, inorder, inIdx+1, end, idxMap);

        return root;
    }

    Node* createBTPostorderPiv(vector<int> postorder, vector<int> inorder, 
                           int start, int end, unordered_map<int, int> idxMap){
        
        static int idx=postorder.size()-1;
        if(start>end){
            return NULL;
        }

        int curr = postorder[idx--];
        Node* root = new Node(curr);

        if(start == end){
            return root;
        }

        int inIdx = idxMap[curr];

        root->right = createBTPreorderPiv(postorder, inorder, inIdx+1, end, idxMap);
        root->left = createBTPreorderPiv(postorder, inorder, start, inIdx-1, idxMap);

        return root;
    }

    void preorderPiv(Node* root){
        if(root == NULL){
            return ;
        }

        cout<<root->getData()<<" ";
        preorderPiv(root->left);
        preorderPiv(root->right);
    }

    void inorderPiv(Node* root){
        if(root == NULL){
            return ;
        }

        inorderPiv(root->left);
        cout<<root->getData()<<" ";
        inorderPiv(root->right);
    }

    void postorderPiv(Node* root){
        if(root == NULL){
            return ;
        }

        postorderPiv(root->left);
        postorderPiv(root->right);
        cout<<root->getData()<<" ";
    }

    public:
        Node* root;
        
        BinaryTree(){
            root = NULL;
        }

        void createBTPreorder(vector<int> preorder, vector<int> inorder){
            unordered_map<int, int> idxMap;
            
            for(int i=0; i<inorder.size(); i++){
                idxMap[inorder[i]] = i;
            }

            this->root = createBTPreorderPiv(preorder, inorder, 0, inorder.size()-1, idxMap);
        }

        void createBTPostorder(vector<int> postorder, vector<int> inorder){
            unordered_map<int, int> idxMap;
            
            for(int i=0; i<inorder.size(); i++){
                idxMap[inorder[i]] = i;
            }

            this->root = createBTPostorderPiv(postorder, inorder, 0, inorder.size()-1, idxMap);
        }

        void preorder(){
            preorderPiv(this->root);
        }

        void inorder(){
            this->inorderPiv(this->root);
        }

        void postorder(){
            this->postorderPiv(this->root);
        }
};


int main(){
    /*

           1
         /   \
        2     3
       / \   / \   
      4   5 6   7
    
    */
    
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    BinaryTree root = BinaryTree();

    root.createBTPostorder(postorder, inorder);
    root.inorder();

    return 0;
}