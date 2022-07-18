class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(auto&it : matrix){
            for(int j = 1;j < m;++j){
                it[j] += it[j-1];
            }
        }
        int count = 0;
        for(int c1 = 0;c1 < m;++c1){
            for(int c2 = c1;c2 < m;++c2){
                unordered_map<int,int> mp;
                int sum = 0;
                mp[sum]+=1;
                for(auto&it : matrix){
                    sum += it[c2] - (c1 > 0 ? it[c1-1] : 0);
                    count += mp[sum - target];
                    mp[sum]+=1;
                }
            }
        }
        return count;
    }
};
