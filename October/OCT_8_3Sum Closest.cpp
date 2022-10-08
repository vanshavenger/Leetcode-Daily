class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int s = i+1;
            int e = n-1;
            while(s < e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum < target){
                    s++;
                }
                else{
                    e--;
                }
                if(abs(sum - target) < diff){
                    ans = sum;
                    diff = abs(sum - target);
                }
            }
        }
        return ans;
        
    }
};
