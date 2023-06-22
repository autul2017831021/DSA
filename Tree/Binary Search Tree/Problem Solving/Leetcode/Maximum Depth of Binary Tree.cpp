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
    int ans = 1;
    int logic(TreeNode* root, int level){
        if(root == NULL)return 0;
        ans = max(ans,level);
        logic(root->left,level+1);
        logic(root->right,level+1);
        return ans;
    }
    int logic(TreeNode* root, int level){
        if(root == NULL)return level-1;
        return max(logic(root->left,level+1),logic(root->right,level+1));
    }
    int maxDepth(TreeNode* root) {
        return logic(root,1);
    }
};