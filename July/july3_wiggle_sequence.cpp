class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int increasingTill = 0;
        int decreasingTill = 0;
        int n = nums.size();
        for(int i = 0;i < n-1;i++){
            if(nums[i] < nums[i+1]){
                increasingTill = decreasingTill + 1;
            }else if(nums[i] > nums[i+1]){
                decreasingTill = increasingTill + 1;
            }
        }
        return 1 + max(decreasingTill,increasingTill); // 1 added to contain the first element initially 
    }
};
