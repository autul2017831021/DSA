Node* LCA(Node *root, int a, int b){
    if(root == nullptr)return root;
    while(root != nullptr){
        if(a > root->data && b > root->data) root = root->right;
        else if(a < root->data && b < root->data) root = root->left;
        else return root;
    }
    return root;
}
Node* LCA(Node *root, int n1, int n2){
    if (root == nullptr) return nullptr;

    if (n1 < root->data && n2 < root->data) return LCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data) return LCA(root->right, n1, n2);
    return root;
}
