// From root to leaf
int minDepth(TreeNode* root,int level){
    if(root == nullptr)return level-1;
    else if(root->right == nullptr)return minDepth(root->left,level+1);
    else if(root->left == nullptr)return minDepth(root->right,level+1);
    else return min(minDepth(root->left,level+1),minDepth(root->right,level+1));
}