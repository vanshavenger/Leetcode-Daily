class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i > n || j > m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == n && j == m){
            return 1;
        }
        int ans = 0;
        ans += solve(i+1,j,n,m,dp);
        ans += solve(i,j+1,n,m,dp);
        return dp[i][j] = ans;
    }
    
    int uniquePaths(int m, int n) {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = solve(i,j,m-1,n-1,dp);
        return ans;
    }
};
