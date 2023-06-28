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
    int getHeight(TreeNode* root){
        if(root == NULL)return 0;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*>q;
        int treeHeight = getHeight(root);
        vector<vector<int>>v(treeHeight);
        int i = 0;
        if(root == NULL)return v;
        q.push(root);
        v[i].push_back(root->val);
        while(!q.empty()){
            i++;
            int queueSize = q.size();
            for(int j=0;j<queueSize;j++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL){
                    v[i].push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right != NULL){
                    v[i].push_back(node->right->val);
                    q.push(node->right);
                }
            }
        }
        return v;
    }
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*>q;
        vector<vector<int>>v;
        vector<int>levelWiseNodes;
        if(root == NULL)return v;
        q.push(root);
        while(!q.empty()){
            int queueSize = q.size();
            for(int j=0;j<queueSize;j++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL)q.push(node->right);
                levelWiseNodes.push_back(node->val);
            }
            v.push_back(levelWiseNodes);
            levelWiseNodes.resize(0);
        }
        return v;
    }
};