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

TreeNode* createNode(int x){
    TreeNode* newNode = new TreeNode(x);
    return newNode;
}

void inOrderTraverse(TreeNode *root){
    if (root != NULL){
        inOrderTraverse(root->left);
        printf("%d ", root->value);
        inOrderTraverse(root->right);
    }
}
void inOrderTraverse_loop(TreeNode *root){
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->value << " ";

        current = current->right;
    }
}

TreeNode* minValueNode(TreeNode* node){
    TreeNode* current = node;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

void insert_naive(TreeNode* root, int val){
    if(val < root->value){
        if(root->left == NULL){
            root->left = createNode(val);
            return;
        }
        insert_naive(root->left, val);
    }
    else{
        if(root->right == NULL){
            root->right = createNode(val);
            return;
        }
        insert_naive(root->right, val);
    }
}
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

TreeNode* insert_loop(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }
    TreeNode* temp = root;
    while(temp != NULL){
        if(val < temp->value){
            if(temp->left == NULL){
                temp->left = new TreeNode(val);
                break;
            }
            else temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = new TreeNode(val);
                break;
            }
            else temp = temp->right;
        }
    }
    return root;
    /// Time  Complexity O(h)
    /// Space Complexity O(1)
}
/// DELETE A NODE

TreeNode* deleteNode_recursive(TreeNode* root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->value){
        root->left = deleteNode_recursive(root->left, val);
    }
    else if(val > root->value){
        root->right = deleteNode_recursive(root->right, val);
    }
    else {
        if(root->left == NULL){
            TreeNode* temp = root->right;
            root =  NULL;
            return temp;
        }
        else if(root->right == NULL){
            TreeNode* temp = root->left;
            root =  NULL;
            return temp;
        }
        TreeNode* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode_recursive(root->right, temp->value);
    }
    return root;
}

void deleteNode_naive(TreeNode** root, int val){
    string side;
    /// handle root node deletion first
    TreeNode* parent = *root;
    TreeNode* curr = *root;
    if(curr == NULL)return;
    if(curr->value == val){
        if((*root)->left == nullptr && (*root)->right == nullptr){
            delete (*root);
            (*root) = nullptr;
            return;
        }
        if((*root)->left == NULL){
            (*root) = (*root)->right;
            delete parent;
        }
        else if((*root)->right == NULL){
            (*root) = (*root)->left;
            delete parent;
        }
        else{
            TreeNode* temp = (*root)->right;
            (*root) = (*root)->left;
            TreeNode* next = (*root);
            while(next->right != NULL){
                next = next->right;
            }
            next->right = temp;
            delete parent;
        }
        return;
    }
    while(curr != NULL){
        if(curr->value == val){
            if(curr->left == NULL && curr->right == NULL){
                if(side == "left")parent->left = nullptr;
                else parent->right = nullptr;
                delete curr;
                return;
            }
            else if(curr->left == NULL){
                if(side == "left")parent->left = curr->right;
                else parent->right = curr->right;
                delete curr;
                return;
            }
            else if(curr->right == NULL){
                if(side == "left")parent->left = curr->left;
                else parent->right = curr->left;
                delete curr;
                return;
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
            return;
        }
        if(val < curr->value){
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
}

TreeNode* deleteNode(TreeNode* root, int val){
    if(root == nullptr)return root;

    if(val < root->value){
        root->left = deleteNode(root->left,val);
        return root;
    }
    else if(val > root->value){
        root->right = deleteNode(root->right,val);
        return root;
    }
    else{
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->right == nullptr){
            TreeNode* succ = root->left;
            delete root;
            return succ;
        }
        else if(root->left == nullptr){
            TreeNode* succ = root->right;
            delete root;
            return succ;
        }
        else{
            TreeNode* succ = root->left;
            TreeNode* curr = root->left;
            TreeNode* temp = root->right;
            while(curr->right != nullptr){
                curr = curr->right;
            }
            curr->right = root->right;
            delete root;
            return succ;
        }
    }
}

int main() {
    srand(time(0));

    int operation_type,node_to_operate, rootNode = randNum();
    cout<<"Root Node : "<<rootNode<<endl;

    TreeNode* root = new TreeNode(rootNode);

    for(int i=0;i<5;i++){
        root = insert(root, randNum());
    }

    inOrderTraverse(root); cout<<endl;

    while(1){
        cout<<"Type 1 to insert a node or 0 to delete a node"<<endl;
        cin>>operation_type;

        if(operation_type == 1){
            cout<<"Insert a node into the BST"<<endl;
            cin>>node_to_operate;
            root = insert(root,node_to_operate);
        }
        else if(operation_type == 0){
            if(root == NULL)break;
            cout<<"Delete a node from the BST"<<endl;
            cin>>node_to_operate;
            root = deleteNode(root, node_to_operate);
        }
        else break;
        inOrderTraverse(root); cout<<endl;
    }
}
