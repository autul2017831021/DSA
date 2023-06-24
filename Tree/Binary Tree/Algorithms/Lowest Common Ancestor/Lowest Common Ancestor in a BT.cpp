Node* lca(Node* root ,int n1 ,int n2 ){
    if(root == nullptr || root->data == n1 || root->data == n2)return root;
    Node* leftSubTree = lca(root->left,n1,n2);
    Node* rightSubTree = lca(root->right,n1,n2);
    if(leftSubTree == nullptr && rightSubTree == nullptr)return nullptr;
    else if(leftSubTree == nullptr)return rightSubTree;
    else if(rightSubTree == nullptr)return leftSubTree;
    return root;
}