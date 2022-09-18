class Solution {
public:
    int trap(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int lmax = arr[left];
        int rmax = arr[right];
        int ans = 0;
        while(left <= right){
            if(arr[left] <= arr[right]){
                if(arr[left] <= lmax) ans += lmax - arr[left];
                lmax = max(lmax,arr[left++]);
            }else{
                if(arr[right] <= rmax) ans += rmax - arr[right];
                rmax = max(rmax,arr[right--]);
            }
        }
        return ans;
    }
};
