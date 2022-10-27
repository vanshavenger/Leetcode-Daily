class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a1;
        vector<pair<int,int>> a2;
        int n = img1.size();
        int m = img1[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(img1[i][j] == 1) a1.push_back({i,j});
                if(img2[i][j] == 1) a2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        int res = 0;
        for(auto & i : a1){
            for(auto & j : a2){
                int op = i.first - j.first;
                int pp = i.second - j.second;
                res = max(res,++mp[{op,pp}]);
            }
        }
        return res;
    }
};
