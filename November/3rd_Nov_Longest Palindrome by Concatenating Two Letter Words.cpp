class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string,int> mp;
        for(auto & it : words){
            string rev = it;
            reverse(rev.begin(),rev.end());
            if(mp[rev] != 0){
                mp[rev] -= 1;
                ans += 4;
            }else{
                mp[it]+=1;
            }
        }
        for(auto & it : mp){
            if(it.second == 1 && it.first[0] == it.first[1]) {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};
