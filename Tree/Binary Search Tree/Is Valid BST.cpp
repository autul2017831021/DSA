#include<bits/stdc++.h>
using namespace std;

int randNum(){
    int mod = 101;
    return rand()%mod;
}

struct TreeNode{
    int value;
    TreeNode *left, *right;
    TreeNode (int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(val < root->value){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
TreeNode* insert_wrong_way(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    if(val > root->value){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

bool isValidBst(TreeNode* root, long long  minval, long long maxval){
    if(root == nullptr)return true;
    if(root->value <= minval || root->value >= maxval)return false;
    return isValidBst(root->left, minval, root->value) and isValidBst(root->right, root->value, maxval);
}
int main() {
    srand(time(0));
    TreeNode* root = new TreeNode(randNum()); /// best way

    for(int i=0;i<5;i++){
        ///root = insert(root, randNum());
        root = insert_wrong_way(root, randNum());
    }
    cout<<isValidBst(root,LONG_MIN,LONG_MAX)<<endl;
}

