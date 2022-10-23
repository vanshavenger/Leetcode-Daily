class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,-1);
        int n = nums.size();
        vector<int> fr(n,0);
        for(int i = 0;i < nums.size();++i){
            fr[nums[i] - 1]++;
        }
        for(int i = 0;i < n;i++){
            if(fr[i] == 2) ans[0] = i+1;
            else if(fr[i] == 0) ans[1] = i+1;
        }
        return ans;
    }
};
