class Solution {
public:
    void dfs(vector<vector<int>>& stones,int ind,int& n,vector<bool>& vis){
        vis[ind] = true;
        for(int i = 0;i < n;i++){
            if(vis[i]) continue;
            if(stones[ind][0] == stones[i][0] || stones[ind][1] == stones[i][1]){
                dfs(stones,i,n,vis);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n,false);
        int count = 0;
        for(int i = 0;i < n;i++){
            if(vis[i]) continue;
            dfs(stones,i,n,vis);
            count++;
        }
        return n - count;
    }
};
