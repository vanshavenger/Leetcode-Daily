class Solution {
public:
    int solve(vector<int>&prices,int i,int n,int k,vector<vector<vector<int>>>& dp,bool buy){
        if(k == 0 || i == n) return 0;
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        int ans = 0;
        if(!buy){
            int take = -prices[i] + solve(prices,i+1,n,k,dp,true);
            int no = solve(prices,i+1,n,k,dp,false);
            ans = max(take,no);
        }else{
            int sell = +prices[i] + solve(prices,i+1,n,k-1,dp,false);
            int no = solve(prices,i+1,n,k,dp,true);
            ans = max(sell,no);
        }
        return dp[i][k][buy] = ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(prices,0,n,k,dp,false);
    }
};
