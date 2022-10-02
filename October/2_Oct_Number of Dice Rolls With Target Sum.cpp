class Solution {
public:
    int mod = 1e9+7;
    int solve(int& n,int dice,int& k,int& tar,int sum,vector<vector<int>>&dp){
        if(dice == n){
            if(sum == tar) return 1;
            else return 0;
        }
        if(sum >= tar) return 0;
        if(dp[dice][sum] != -1) return dp[dice][sum];
        int ans = 0;
        for(int i = 1;i <= k;i++){
            if(i > tar) break;
            ans += solve(n,dice+1,k,tar,sum+i,dp);
            ans %= mod;
        }
        return dp[dice][sum] = ans%mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,0,k,target,0,dp);
    }
};
