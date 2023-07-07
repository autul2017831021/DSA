
void postorderTraversal(TreeNode* root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<" ";
    }
}