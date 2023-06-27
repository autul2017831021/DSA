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
    int frequentTreeSum(TreeNode* root, map<int,int> &m, int &maxFrequency){
        if(root == nullptr)return 0;

        int left = frequentTreeSum(root->left, m, maxFrequency);
        int right = frequentTreeSum(root->right, m, maxFrequency);
    
        int treeSum = root->val+left+right;
        m[treeSum]++;
        maxFrequency = max(maxFrequency,m[treeSum]);

        return treeSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>v;
        map<int,int>m;
        int maxFrequency = 0;
        frequentTreeSum(root,m,maxFrequency);
        
        for(auto const& pair : m){
            if (maxFrequency == pair.second){
                v.push_back(pair.first);
            }
        }
        return v;
    }
};