class Solution {
public:
    int dfs(int st,vector<int> graph[],vector<bool>& apple,int prev){
        int ans = 0;
        for(auto & it : graph[st]){
            if(it != prev){
                ans += dfs(it,graph,apple,st);
            }
        }
        if(st == 0) return ans;
        if(apple[st] || ans > 0) return ans + 2;
        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int> graph[n];
        for(auto & it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        return dfs(0,graph,hasApple,-1);
    }
};
