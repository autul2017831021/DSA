/// Time  Complexity O(n)
/// Space Complexity O(1)
void inorderTraversal(TreeNode *root){
    if (root != NULL){
        inOrderTraverse(root->left);
        printf("%d ", root->value);
        inOrderTraverse(root->right);
    }
}
void inorderTraversal(TreeNode *root){
    stack<TreeNode*> s;
    TreeNode* current = root;
    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->value << " ";
        current = current->right;
    }
}
