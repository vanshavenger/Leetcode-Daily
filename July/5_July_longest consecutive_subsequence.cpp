class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int,int> mp;
        int mx = 0;
        int n = arr.size();
        if(n == 0){
            return 0;
        }
        for(auto&it:arr){
            mp[it]++;
        }
        for(auto& it : arr){
            int x = it;
            int j = 0;
            if(mp.find(x-1) != mp.end()){
                continue;
            }
            while(mp.find(x+1) != mp.end()){
                j++;
                x++;
            }
            if(j > mx){
                mx = j;
            }
        }
        return mx+1;
    }
};
