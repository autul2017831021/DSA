class Solution {
public:
    void preOrderTraverse(TreeNode* root,vector<int>&v){
        if(root != NULL){
            v.push_back(root->val);
            preOrderTraverse(root->left,v);
            preOrderTraverse(root->right,v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root == NULL)return v;
        preOrderTraverse(root,v);
        return v;
    }
};