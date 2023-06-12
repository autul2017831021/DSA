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
    TreeNode* deleteNode(TreeNode* root, int key) {
        string side;
        /// handle root node deletion first
        TreeNode* parent = root;
        TreeNode* curr = root;
        if(curr == NULL)return NULL;
        if(curr->val == key){
            if(root->left == nullptr && root->right == nullptr)return nullptr;
            if(root->left == NULL){
                root = root->right;
                delete parent;
            }
            else if(root->right == NULL){
                root = root->left;
                delete parent;
            }
            else{
                TreeNode* temp = root->right;
                root = root->left;
                TreeNode* next = root;
                while(next->right != NULL){
                    next = next->right;
                }
                next->right = temp;
                delete parent;
            }
            return root;
        }

        while(curr != NULL){
            if(curr->val == key){
                if(curr->left == NULL && curr->right == NULL){
                    if(side == "left")parent->left = nullptr;
                    else parent->right = nullptr;
                    delete curr;
                    break;
                }
                else if(curr->left == NULL){
                    if(side == "left")parent->left = curr->right;
                    else parent->right = curr->right;
                    delete curr;
                    break;
                }
                else if(curr->right == NULL){
                    if(side == "left")parent->left = curr->left;
                    else parent->right = curr->left;
                    delete curr;
                    break;
                }
                if(side == "left")parent->left = curr->left;
                else parent->right = curr->left;
                TreeNode* temp = curr->right;
                TreeNode* next = curr->left;
                while(next->right != NULL){
                    next = next->right;
                }
                next->right = temp;
                delete curr;
                break;
            }
            if(key < curr->val){
                side = "left";
                parent = curr;
                curr = curr->left;
            }
            else{
                side = "right";
                parent = curr;
                curr = curr->right;
            }
        }
        return root;
    }
};