class Solution {
public:
    int solve(string a,string b,int n,int m,vector<vector<int>>& dp){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans = solve(word1,word2,n,m,dp);
        return n + m - 2*ans;
    }
};
