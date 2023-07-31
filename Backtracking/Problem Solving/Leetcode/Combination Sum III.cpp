class Solution {
public:
    vector<vector<int>>ans;
    void backtracking(vector<int>&v,int target,int k,int index,vector<int>&a){
        if(target == 0){
            if(a.size()==k)ans.push_back(a);
            return;
        }
        if(target<0 || index >= v.size())return;
        backtracking(v,target,k,index+1,a);
        a.push_back(v[index]);
        backtracking(v,target-v[index],k,index+1,a);
        a.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int>v = {1,2,3,4,5,6,7,8,9};
        vector<int>a;
        backtracking(v,target,k,0,a);
        return ans;
    }
};