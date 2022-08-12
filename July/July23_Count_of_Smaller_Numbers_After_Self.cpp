class Solution {
public:
    void merge(vector<pair<int,int>>& arr,int start,int mid,int end,vector<int>& count){
        vector<pair<int,int>> temp;
        int i = start;
        int j = mid;
        while(i < mid && j <= end){
            if(arr[i].first <= arr[j].first){
                temp.push_back(arr[j++]);
            }
            else{
                count[arr[i].second] += end-j+1;
                temp.push_back(arr[i++]);
            }
        }
        while(i < mid){
            temp.push_back(arr[i++]);
        }
        while(j <= end){
            temp.push_back(arr[j++]);
        }
        i = start;
        for(auto&it : temp){
            arr[i++] = it;
        }
    }
    
    void solve(vector<pair<int,int>>& arr,int start,int end,vector<int>& count){
        if(end > start){
            int mid = start + ((end - start) >> 1);
            solve(arr,start,mid,count);
            solve(arr,mid+1,end,count);
            merge(arr,start,mid+1,end,count);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0);
        vector<pair<int,int>> arr(n);
        for(int i = 0;i < n;++i){
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        solve(arr,0,n-1,count);
        return count;
    }
};
