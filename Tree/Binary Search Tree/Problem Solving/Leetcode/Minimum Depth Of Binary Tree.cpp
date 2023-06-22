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
    int logic(TreeNode* root,int level){
        if(root == nullptr)return level-1;
        else if(root->right == nullptr)return logic(root->left,level+1);
        else if(root->left == nullptr)return logic(root->right,level+1);
        else return min(logic(root->left,level+1),logic(root->right,level+1));
    }
    int minDepth(TreeNode* root) {
        return logic(root,1);
    }
};