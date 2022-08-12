class Solution {
public:
    int solve(vector<int>& arr,int target,int sum,vector<int>& dp){
        if(sum == target) return 1;
        if(sum > target) return 0;
        if(dp[sum] != -1) return dp[sum];
        int ans = 0;
        for(int i = 0;i < arr.size();i++){
            ans += solve(arr,target,sum + arr[i],dp);
        }
            
        return dp[sum] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,0,dp);
    }
};
