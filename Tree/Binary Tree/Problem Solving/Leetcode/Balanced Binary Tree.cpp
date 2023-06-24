/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag = true;
    int logic(TreeNode* root){
        if(root == nullptr)return 0;
        int left = logic(root->left);
        int right = logic(root->right);
        if(abs(right-left)>1)flag = false;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        logic(root);
        return flag;
    }
};