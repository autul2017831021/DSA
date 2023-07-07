/// Time  Complexity O(n)
/// Space Complexity O(1)
void levelOrderTraverse(TreeNode *root){
    if(root == nullptr)return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout<<node->val<<" ";
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL)q.push(node->right);
    }
}
