class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0;
        int end = 0;
        unordered_map<int,int> mp;
        int maxi = 0;
        int cur = 0;
        int n = nums.size();
        while(end < n){
            mp[nums[end]]++;
            cur += nums[end];
            if(mp.size() == (end - start + 1)){
                maxi = max(maxi,cur);
            }
            else if(mp.size() < (end-start + 1)){
                while(mp.size() < (end-start+1)){
                    mp[nums[start]]--;
                    cur -= nums[start];
                    if(mp[nums[start]] == 0){
                        mp.erase(nums[start]);
                    }
                    start++;
                }
            }
            end++;
        }
        return maxi;
    }
};
