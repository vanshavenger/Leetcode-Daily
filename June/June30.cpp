class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        int c = 0;
        while(i < j){
            c += (nums[j] - nums[i]);
            i++;j--;
        }
        return c;
    }
};
