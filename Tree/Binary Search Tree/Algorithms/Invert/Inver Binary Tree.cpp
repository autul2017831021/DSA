TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr)return root;
    TreeNode* leftChild = root->left;
    TreeNode* rightChild = root->right;
    root->left = invertTree(rightChild);
    root->right = invertTree(leftChild);
    return root;
}