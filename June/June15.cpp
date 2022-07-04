class Solution {
public:
    static bool cmp(string a,string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int ans = 1;
        map<string,int> mp;
        mp[words[0]] = 1;
        for(auto it : words){
            mp[it] = 1;
            for(int i = 0;i < it.size();i++){
                string an = it.substr(0,i) + it.substr(i+1);
                if(mp.find(an) != mp.end()){
                    mp[it] = max(mp[it],mp[an] + 1);
                    ans = max(ans,mp[it]);
                }
            }
        }
        return ans;
    }
};
