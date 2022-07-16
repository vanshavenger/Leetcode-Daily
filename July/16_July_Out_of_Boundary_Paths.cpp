class Solution {
    int dp[51][51][51];
    int mod = 1e9+7;
public:
    int solve(int &n,int& m,int mo,int i,int j){
        if(i < 0 || j < 0 || i == n || j == m) return 1;
        if(mo <= 0) return 0;
        if(dp[i][j][mo] != -1) return dp[i][j][mo];
        int ans = 0;
        ans += (solve(n,m,mo-1,i+1,j))%mod;
        ans %= mod;
        ans += (solve(n,m,mo-1,i-1,j))%mod;
        ans %= mod;
        ans += (solve(n,m,mo-1,i,j-1))%mod;
        ans %= mod;
        ans += (solve(n,m,mo-1,i,j+1))%mod;
        ans %= mod;
        return dp[i][j][mo] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};
