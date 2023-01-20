class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        while(i < n){
            sum = (sum%k + nums[i]%k + k)%k;
            if(sum == 0){
                ans += 1;
            }
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            mp[sum]++;
            ++i;
        }
        return ans;
    }
};
