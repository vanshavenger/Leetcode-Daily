class Solution {
public:
    
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {0};
        for(int i = 0;i <= n;++i){
            dp[i][0] = 1;
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= k;++j){
                for(int op = 0;op <= min(j,i-1);++op){
                    dp[i][j] += dp[i-1][j - op]%1000000007;
                    dp[i][j] %= 1000000007;
                }
            }
        }
        return dp[n][k];
    }
};
