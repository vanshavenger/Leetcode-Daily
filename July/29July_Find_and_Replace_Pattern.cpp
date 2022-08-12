class Solution {
public:
    unordered_map<int,int> mp;
    bool valid(string&a,string& b){
        for(int i = 0;i < a.size();i++){
            if(mp.find(a[i]) != mp.end()){
                if(mp[a[i]] != b[i]){
                    mp.clear();
                    return false;
                }
            }
            mp[a[i]] = b[i];

        }
        mp.clear();
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto&it : words){
            if(it.size() == pattern.size() && valid(it,pattern) && valid(pattern,it)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
