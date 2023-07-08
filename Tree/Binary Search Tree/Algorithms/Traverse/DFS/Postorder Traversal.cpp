
void postorderTraversal(TreeNode* root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<" ";
    }
}
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> st;
    TreeNode* prev = nullptr;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            TreeNode* top = st.top();
            if (top->right == nullptr || top->right == prev) {
                st.pop();
                // Process the node (e.g., print its value)
                cout << top->val << " ";
                prev = top;
            } 
            else {
                curr = top->right;
            }
        }
    }
}