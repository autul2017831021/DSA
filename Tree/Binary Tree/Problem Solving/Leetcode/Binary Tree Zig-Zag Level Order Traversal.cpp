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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int i = 0;
        queue<TreeNode*>q;
        vector<vector<int>>v;
        vector<int>levelWiseNodes;
        if(root == NULL)return v;
        q.push(root);
        while(q.size()>0){
            int queueSize = q.size();
            for(int j=0;j<queueSize;j++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL)q.push(node->right);
                levelWiseNodes.push_back(node->val);
            }
            if(i%2){
                reverse(levelWiseNodes.begin(),levelWiseNodes.end());
            }
            v.push_back(levelWiseNodes);
            levelWiseNodes.resize(0);
            i++;
        }
        return v;
    }
};