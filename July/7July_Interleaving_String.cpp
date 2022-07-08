class Solution {
public:
//     bool solve(int i,int j,int k,string s1,string s2,string s3, vector<vector<int>>& dp){
//         if(i == 0 && j == 0) return true;
//         if(dp[i][j] != -1) return dp[i][j];
//         bool ans = false;
//         if(i > 0 && s1[i-1] == s3[k-1] && j > 0 && s2[j-1] == s3[k-1]){
//             ans = solve(i-1,j,k-1,s1,s2,s3,dp) || solve(i,j-1,k-1,s1,s2,s3,dp);
//         }
//         else if(i > 0 && s1[i-1] == s3[k-1]){
//              ans = solve(i-1,j,k-1,s1,s2,s3,dp);
//         }
//         else if(j > 0 && s2[j-1] == s3[k-1]){
//             ans = solve(i,j-1,k-1,s1,s2,s3,dp);
//         }
//         return dp[i][j] = ans;
//     }
    
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        if((a+b) != c){
            return false;
        }
        if(a == 0){
            return s2 == s3;
        }
        if(b == 0){
            return s3 == s1;
        }
        
        vector<vector<bool>> dp(a+1,vector<bool>(b+1));
        // vector<bool> cur(b+1,false);
        // vector<bool> pre(b+1,false);
        dp[0][0] = true;
        for(int i = 1;i <= a;i++){
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int i = 1;i <= b;i++){
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        }
        
        for(int i = 1;i <= a;i++){
            for(int j = 1;j <= b;j++){
                int k = i + j;
                if(s1[i-1] == s3[k-1] && s2[j-1] == s3[k-1]){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else if(s1[i-1] == s3[k-1]){
                    dp[i][j] = dp[i-1][j];
                }else if(s2[j-1] == s3[k-1]){
                    dp[i][j] = dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[a][b];
    }
};
