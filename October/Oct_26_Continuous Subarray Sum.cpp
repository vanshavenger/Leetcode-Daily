class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        unordered_map<int,int> mp;
        mp[0] = 0;
        int sum = 0;
        int i = 0;
        for(auto & it : nums){
            sum += it;
            if(mp.find(sum%k) != mp.end()){ if(mp[sum%k] < i) return true;}
            else mp[sum%k] = i+1;
            i+=1;
        }
        return false;
    }
};
