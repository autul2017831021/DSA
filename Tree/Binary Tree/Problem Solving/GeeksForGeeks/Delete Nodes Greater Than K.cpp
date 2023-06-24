class Solution{
  public:
    Node* deleteNode(Node* root, int k){
        if(!root)return nullptr;
        if(root->data >= k){
            root = deleteNode(root->left,k);
        }
        else{
            root->right = deleteNode(root->right,k);
        }
        return root;
    }
};