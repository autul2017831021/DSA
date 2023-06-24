/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int logic(Node* root){
        if(root == nullptr)return 0;
        vector<Node*> child = root->children;
        vector<int>v;
        v.push_back(0); // to avoid null vector
        for(int i=0;i<child.size();i++){
            v.push_back(logic(child[i]));
        }
        return ( *max_element(v.begin(),v.end()) ) + 1;
    }
    int maxDepth(Node* root) {
        return logic(root);
    }
};