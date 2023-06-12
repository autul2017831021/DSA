class Solution{
    public:
        Node* LCA(Node *root, int a, int b)
        {
            if(root == nullptr)return root;
            while(root != nullptr){
                if(a > root->data && b > root->data) root = root->right;
                else if(a < root->data && b < root->data) root = root->left;
                else return root;
            }
            return root;
        }
};