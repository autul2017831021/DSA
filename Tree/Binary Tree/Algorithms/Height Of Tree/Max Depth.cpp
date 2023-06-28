int maxDepth(TreeNode* root) {
    if(root == nullptr)return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}
int maxDepth(TreeNode* root, int level){
    if(root == NULL)return level-1;
    return max(maxDepth(root->left,level+1),maxDepth(root->right,level+1));
}
// Iterative
int maxDepth(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        height++;
    }
    return height;
}