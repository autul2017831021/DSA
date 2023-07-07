class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return -1;

        vector<long long>v;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int q_size = q.size();
            long long sum = 0;

            for(int i=0;i<q_size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            v.push_back(sum);
        }
        sort(v.rbegin(),v.rend());
        if(v.size()<k)return -1;
        return v[k-1];
    }
};