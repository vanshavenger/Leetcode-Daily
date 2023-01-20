class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> mp(26);
        for(int i = 0;i < 26;i++) mp[i] = 'a' + i;
        for(int i = 0;i < s1.size();i++){
            char replace = max(mp[s1[i] - 'a'],mp[s2[i] - 'a']);
            char put = min(mp[s1[i] - 'a'],mp[s2[i] - 'a']);
            for(int i = 0;i < 26;i++){
                if(mp[i] == replace) mp[i] = put;
            }
        }string ans = "";
        for(int i = 0;i < baseStr.size();i++){
            ans += mp[baseStr[i] - 'a'];
        }
        return ans;
    }
};
