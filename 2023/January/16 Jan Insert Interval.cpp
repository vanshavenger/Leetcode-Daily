class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        vector<int> temp = intervals[0];
        for(auto it : intervals){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1],temp[1]);
            }
            else{
                v.push_back(temp);
                temp = it;
            }
        }
        v.push_back(temp);
        return v;
    }
};
