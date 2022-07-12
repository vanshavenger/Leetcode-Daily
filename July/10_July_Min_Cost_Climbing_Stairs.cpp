class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int* arr = new int[cost.size()];
        if(cost.size() == 1 || cost.size() == 0){
            return 0;
        }
        arr[0] = 0;
        arr[1] = 0;
        for(int i = 2;i< cost.size();i++){
            arr[i] = min(arr[i-1] + cost[i-1], arr[i-2] + cost[i-2]);
        }
        return min(arr[cost.size()-1] + cost[cost.size() - 1],arr[cost.size() - 2] + cost[cost.size() - 2]);
    }
};
