class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> v =  {{1}};
        if(n == 1){
            return v;
        }
        v = {{1},{1,1}};
        if(n == 2){
           return v;
        }
        int p = n - 2;
        vector<int> v1;
        while(p--){
            v1 = {1};
            for(int i = 0;i < v.size() - 1; i++){
                int ans = v[v.size() - 1][i] + v[v.size() - 1][i+1];
                v1.push_back(ans);
            }
            v1.push_back(1);
            v.push_back(v1);
        }
        return v;
    }
};
