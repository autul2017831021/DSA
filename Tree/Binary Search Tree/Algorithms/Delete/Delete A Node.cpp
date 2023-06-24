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
        /// If Node is leaf-node
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            return nullptr;
        }
        /// If right-child is nullptr
        else if(root->right == nullptr){
            TreeNode* succ = root->left;
            delete root;
            return succ;
        }
        /// If left-childe is nullptr
        else if(root->left == nullptr){
            TreeNode* succ = root->right;
            delete root;
            return succ;
        }
        /// If node has both-child
        else{
            TreeNode* succ = root->left;
            TreeNode* curr = root->left;
            while(curr->right != nullptr){
                curr = curr->right;
            }
            curr->right = root->right;
            delete root;
            return succ;
        }
    }
}

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
        TreeNode* temp = minValueNode(root->right); /// Write the minValueNode() function
        root->value = temp->value;
        root->right = deleteNode_recursive(root->right, temp->value);
    }
    return root;
}

void deleteNode_naive(TreeNode** root, int val){
    string side;
    TreeNode* parent = *root;
    TreeNode* curr = *root;
    if(curr == NULL)return;
    /// Handlling Root Node Deletion
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
    /// Child Node Deletion
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
