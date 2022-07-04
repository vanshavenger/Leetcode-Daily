class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0; i< nums.size();i++){
            sum += nums[i];
        }
        int op = sum - x;
        int l = 0;
        int r = 0;
        int curr = 0;
        int maxi = -1;
        for(;r < nums.size();r++){
            curr += nums[r];
            while(l <= r && curr > op){
                curr -= nums[l];
                l++;
            }
            if(curr == op){
                maxi = max(maxi,r -l +1);
            }
        }
        if(maxi == -1){
            return -1;
        }
        return nums.size() - maxi;
    }
};
