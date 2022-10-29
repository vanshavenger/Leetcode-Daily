class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> arr;
        for(int i = 0;i < plantTime.size();i++) arr.push_back({growTime[i],plantTime[i]});
        sort(arr.rbegin(),arr.rend());
        int ans = 0;
        int p = 0;
        for(auto & it : arr){
            ans = max(ans,p + it.first + it.second);
            p += it.second; 
        } 
        return ans;
    }
};
