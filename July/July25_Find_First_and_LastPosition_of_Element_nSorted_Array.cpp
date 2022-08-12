class Solution {
public:
    int bin(vector<int>& nums, int s, int e, int t){
        while(s <= e){
            int mid = (s + e)/2;
            if(nums[mid] == t){
                return mid;
            }
            else if(nums[mid] > t){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        if(nums.size() == 0){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        if(bin(nums,0,nums.size() - 1,target) == -1){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        
        int low = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int hig = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
        v.push_back(low);
        v.push_back(hig);
        return v;
        
    }
};
