class Solution {
public:
//    static bool cmp(vector<int>& a,vector<int>& b){
        
//         return a[1] > b[1]; 
//     }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int>&a,vector<int>&b) {
            return a[1] > b[1];
        });
        for(auto&it : boxTypes){
            if(truckSize >= it[0]){
                truckSize -= it[0];
                ans += (it[0]*it[1]);
            }else{
                ans += truckSize*it[1];
                break;
            }
        }
        return ans;
       
    }
};
