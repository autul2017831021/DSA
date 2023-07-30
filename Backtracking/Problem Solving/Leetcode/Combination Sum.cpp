class Solution {
public:
    vector<vector<int>>ans;
    void backtracking(vector<int>&v,int target,int i,vector<int>&a){
        if(target == 0){
            if(a.size()==0)return;
            ans.push_back(a);
            return;
        }
        if(target<0 || i>=v.size())return;
        backtracking(v,target,i+1,a);
        a.push_back(v[i]);
        backtracking(v,target-v[i],i,a);
        a.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        ans.clear();
        vector<int>a;
        backtracking(v,target,0,a);
        return ans;
    }
};