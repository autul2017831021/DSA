
void preorderTraversal(TreeNode* root){
    if(root != NULL){
        cout<<root->val<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) {
    if(root == NULL)return;

    stack<TreeNode*>st;
    st.push(root);

    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();

        cout<<node->val<<" ";

        if (node->right)st.push(node->right);
        if (node->left) st.push(node->left);
    }
}