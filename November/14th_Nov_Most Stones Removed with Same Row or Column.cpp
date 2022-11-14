class Solution {
public:
    bool vis[1001];
    int n;
    void dfs(vector<vector<int>>& stones,int ind){
        vis[ind] = true;
        for(int i = 0;i < n;++i){
            if(vis[i]) continue;
            if(stones[ind][0] == stones[i][0] || stones[ind][1] == stones[i][1]){
                dfs(stones,i);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        memset(vis,false,sizeof(vis));
        int count = 0;
        for(int i = 0;i < n;++i){
            if(!vis[i]){
                dfs(stones,i);
                count++;
            }
            
        }
        return n - count;
    }
};
