class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        if(buildings.size() == 0) return ans;
        vector<pair<int,int>> arr;
        for(auto & it : buildings){
            arr.push_back({it[0],-1*it[2]});
            arr.push_back({it[1],it[2]});
        }
        sort(arr.begin(),arr.end());
        int t = 0;
        multiset<int,greater<int>> op;
        op.insert(0);
        for(auto & it : arr){
            if(it.second < 0) op.insert(-1*it.second);
            else op.erase(op.find(it.second));
            int h = *op.begin();
            if(t != h){
                t = h;
                ans.push_back({it.first,h});
            }
        }
        return ans;
    }
};
