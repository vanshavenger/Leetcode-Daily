class Solution {
public:
    int INF = 1e9;
    int dp[101][101][21];
    int solve(int ind,int prev,int total,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(ind == m) return total == target ? 0 : INF;
        if(dp[ind][total][prev] != -1) return dp[ind][total][prev];
        int ans = INF;
        if(houses[ind]){
            if(houses[ind] == prev) ans = min(ans,solve(ind+1,houses[ind],total,houses,cost,m,n,target));
            else ans = min(ans,solve(ind+1,houses[ind],total+1,houses,cost,m,n,target));
        }else{
            for(int i = 0;i < n;i++){ 
                if((i+1) != prev) ans = min(ans,cost[ind][i] + solve(ind+1,i+1,total+1,houses,cost,m,n,target));
                else ans = min(ans,cost[ind][i] + solve(ind+1,i+1,total,houses,cost,m,n,target));
            }
        }
        return dp[ind][total][prev] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,houses,cost,m,n,target);
        return ans == INF ? -1 : ans;
    }
};
