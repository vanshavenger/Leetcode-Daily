class Solution {
public:
    void solve(vector<int>& nums,int i,set<vector<int>>& ans,vector<int>& op){
        if(i == nums.size()){
            if(op.size() > 1) ans.insert(op);
            return;
        }
        if(op.size() == 0 || op[op.size() - 1] <= nums[i]){
            op.push_back(nums[i]);
            solve(nums,i+1,ans,op);
            op.pop_back();
        }
       solve(nums,i+1,ans,op);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> op;
        solve(nums,0,ans,op);
        return vector(ans.begin(),ans.end());
    }
};
