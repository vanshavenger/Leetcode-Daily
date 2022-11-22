class Solution {
public:
    int numSquares(int n) {
        vector<int> ans;
        for(int i = 1;i*i <= n;++i) ans.push_back(i*i);
        
        int op = ans.size();
        vector<int> prev(n+1,1e4);
        vector<int> curr(n+1,1e4);
        for(int i = 0;i <= n;i++){
            if(i%ans[0] == 0){
                prev[i] = i/ans[0];
            }
        }
        for(int i = 1;i <= op;++i){
            for(int j = 0;j <= n;++j){
                int notake = prev[j];
                int take = 1e4;
                if(j >= ans[i-1]){
                    take = 1 + curr[j - ans[i-1]];
                }
                curr[j] = min(take,notake);
            }
            prev = curr;
        }
        return prev[n];
    }
};
