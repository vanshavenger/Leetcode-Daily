class Solution {
public:
    vector<int> dfs(vector<int>& ans,int& n,vector<int> graph[],string& labels,int p,int c){
        vector<int> op(26,0);
        op[labels[c] - 'a']++;
        for(auto & it : graph[c]){
            if(it != p){
                vector<int> temp = dfs(ans,n,graph,labels,c,it);
                for(int i = 0;i < 26;++i){
                    op[i] += temp[i];
                }
            }
        }
        ans[c] = op[labels[c] - 'a'];
        return op;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> graph[n];
        for(auto & it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> ans(n,0);
        dfs(ans,n,graph,labels,-1,0);
        return ans;
    }
};
