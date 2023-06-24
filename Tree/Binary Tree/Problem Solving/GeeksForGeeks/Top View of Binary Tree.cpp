class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    map<int,int>m,d;
    void traverse(Node* root, int lvl,int depth){
        if(root==nullptr)return;
        if(m.find(lvl) == m.end()){
            m[lvl] = root->data;
            d[lvl] = depth;
        }
        else{
            if(depth < d[lvl]){
                m[lvl] = root->data;
                d[lvl] = depth;
            }
        }
        traverse(root->left,lvl-1,depth+1);
        traverse(root->right,lvl+1,depth+1);
    }
    vector<int> topView(Node *root)
    {
        Node* curr = root;
        vector<int>v;
        traverse(root,0,0);
        map<int,int>:: iterator it;
        for(it=m.begin();it!=m.end();it++){
            v.push_back(it->second);
        }
        return v;
    }

};
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1?page=1&category[]=Binary%20Search%20Tree&sortBy=submissions