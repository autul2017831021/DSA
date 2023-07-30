class Solution {
public:
    set<vector<int>>ans;
    void backtracking(vector<int> v,int target,int i,vector<int>&a){
        if(target == 0){
            if(a.size()==0)return;
            ans.insert(a);
        }
        if(target<0 || i>=v.size())return;
        backtracking(v,target,i+1,a);
        a.push_back(v[i]);
        backtracking(v,target-v[i],i,a);
        backtracking(v,target-v[i],i+1,a);
        if(a.size()>0)a.erase(a.end()-1);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<int>a;
        vector<vector<int>>vec;
        backtracking(v,target,0,a);
        for(auto i:ans){
            vec.push_back(i);
        }
        return vec;
    }
};