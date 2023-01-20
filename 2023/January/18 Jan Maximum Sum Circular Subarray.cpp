class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int sum = 0;
        int s2 = 0;
        int mi = INT_MAX;
        int t = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            s2+= nums[i];
            t += nums[i];
            if(s2 < mi) mi = s2;
            if(s2 > 0) s2 = 0;
            if(sum > maxi) maxi = sum;
            if(sum < 0) sum = 0;
        }
        return mi == t ? maxi : max(maxi , t - mi);
    }
};
