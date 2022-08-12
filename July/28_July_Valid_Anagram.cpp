class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp(26,0);
        for(auto& i :  s){
            mp[i - 'a']++;
        }
        for(auto & i : t){
            mp[i - 'a']--;
        }
        for(auto& i : mp){
            if(i){
                return false;
            }
        }
        return true;
    }
};
