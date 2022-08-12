class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9+7;
        vector<int> prev(5,1);
        vector<int> curr(5,0);
        for(int i= 2;i <= n;i++){
            curr[0] = (prev[1])%mod;
            curr[1] = (prev[0] + prev[2])%mod;
            curr[2] = (((prev[0] + prev[1])%mod + (prev[3] + prev[4])%mod)%mod)%mod;
            curr[3] = (prev[2] + prev[4])%mod;
            curr[4] = (prev[0])%mod;
            prev = curr;
        }
        int ans = 0;
        for(auto&i : prev){
            ans += i;
            ans %= mod;
        }
        return ans;
    }
};
