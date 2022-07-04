class Solution {
public:
    int candy(vector<int>& arr) {
        int n  = arr.size();
        vector<int> pre(n,0);
        for(int i = 1;i < n;i++){
            if(arr[i] > arr[i-1]){
                pre[i] = pre[i-1] + 1;
            }
        }
        for(int i = n-2;i >= 0;i--){
            if(arr[i+1] < arr[i]){
                pre[i] = max(pre[i],pre[i+1]+1);
            }
        }
        int sum = n;
        for(auto&it : pre){
            sum += it;
        }
        return sum;
    }
};
