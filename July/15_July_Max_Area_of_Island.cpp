class Solution {
public:
    int n,m,op;
    void solve(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) return;
        op++;
        grid[i][j] = 0;
        solve(grid,i+1,j);
        solve(grid,i-1,j);
        solve(grid,i,j+1);
        solve(grid,i,j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0 ;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    op = 0;
                    solve(grid,i,j);
                    ans = max(op,ans);
                }
            }
        }
        return ans;
    }
};
