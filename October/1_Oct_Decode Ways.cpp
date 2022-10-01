class Solution {
public:
    // int solve(int i,int n,string s,vector<int>& dp){
    //     if(i == n){
    //         return 1;
    //     }
    //     if(s[i] == '0'){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     int ans1 = 0;
    //      ans1 += solve(i+1,n,s,dp);
    //     if(i+2 <= n && s.substr(i,2) >= "10" && s.substr(i,2) <= "26"){
    //         ans1 += solve(i+2,n,s,dp); 
    //     }
    //     return dp[i] = ans1;
    // }
    
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1){
            return s != "0";
        }
        int prev1,prev2,curr;
        prev1 = 1;
        if(s[0] == '0'){
            prev2 = 0;
        }else{
            prev2 = 1;
        }
        
        for(int i = 2;i <= n;i++){
            int ans = 0;
            string op;
            op = s.substr(i-1,1);
            if(op > "0"){
                ans += prev2;
            }
            op = s.substr(i-2,2);
            if(op >= "10" && op <= "26"){
                ans += prev1;
            }
            curr = ans;
            prev1 = prev2;
            prev2 = curr;
            
        }
        return curr;
    }
};
