class Solution {
public:
    int mx[4] = {1,-1,0,0};
    int my[4] = {0,0,1,-1};
    int vis[41][41][1600];
    int n,m;
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        memset(vis,0,sizeof(vis));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,k}});
        vis[0][0][k] = 1;
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second.first;
                int obs = it.second.second;
                if(x == (n-1) && y == (m-1)) return step;
                 for(int j = 0;j < 4;j++){
                    int cx = x + mx[j];
                    int cy = y + my[j];
                    if(cx < 0 || cy < 0 || cx == n || cy == m) continue;
                    if(grid[cx][cy] == 1 && obs > 0 && !vis[cx][cy][obs-1]){
                        vis[cx][cy][obs-1] = 1;
                        q.push({cx,{cy,obs-1}});
                    }
                    if(grid[cx][cy] == 0 && !vis[cx][cy][obs]){
                        vis[cx][cy][obs] = 1;
                        q.push({cx,{cy,obs}});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
