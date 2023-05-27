#include <bits/stdc++.h>
using namespace std;
#define de cout<<
#define nl printf("\n")
#define sp printf(" ")
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int value){
          this->val = value;
          this->left = nullptr;
          this->right = nullptr;
      }
};
TreeNode* insert(TreeNode *root,int key){
    if(root == NULL){
        return new TreeNode(key);
    }
    else if(root->val > key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }
    return root;
}
void inOrderTraverse(TreeNode *root,int key,bool *flag){
    if(root != NULL){
        if(root->val == key)
            *flag = true;
        inOrderTraverse(root->left,key,flag);
        cout<<root->val<<" ";
        inOrderTraverse(root->right,key,flag);
    }
    return;

}
int main(){
    int key = 2;
    bool flag = false;
    /// Tree Starts:
    TreeNode *root = nullptr;
    root = insert(root,4);
    insert(root,2);
    insert(root,7);
    insert(root,1);
    insert(root,3);
    inOrderTraverse(root,key,&flag);
    if(flag)de "Found";
    else de "Not Found";
}
