/// Time  Complexity O(h)
/// Space Complexity O(1)
TreeNode* insert(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(val < root->value){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

TreeNode* insert(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    TreeNode* temp = root;
    while(temp != NULL){
        if(val < temp->value){
            if(temp->left == NULL){
                temp->left = new TreeNode(val);
                break;
            }
            else temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = new TreeNode(val);
                break;
            }
            else temp = temp->right;
        }
    }
    return root;
}
void insert_naive(TreeNode* root, int val){
    if(val < root->value){
        if(root->left == NULL){
            root->left = createNode(val);
            return;
        }
        insert_naive(root->left, val);
    }
    else{
        if(root->right == NULL){
            root->right = createNode(val);
            return;
        }
        insert_naive(root->right, val);
    }
}
