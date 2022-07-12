class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int mx = nums[0];
        pq.push({nums[0],0});
        for(int i = 1;i < nums.size();i++){
            while((i - pq.top().second) > k){
                pq.pop();
            }
            mx = pq.top().first + nums[i];
            pq.push({mx,i});
        }
        return mx;
    }
};
