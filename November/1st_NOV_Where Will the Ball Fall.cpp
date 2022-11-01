class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i >= n) return j;
        if(j + grid[i][j] < 0 || j + grid[i][j] >= m) return -1;
        if(grid[i][j] == grid[i][j + grid[i][j]]) return dfs(grid,i+1,j+grid[i][j]);
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> arr;
        for(int i = 0;i < m;i++) arr.emplace_back(dfs(grid,0,i));
        return arr;
    }
};
