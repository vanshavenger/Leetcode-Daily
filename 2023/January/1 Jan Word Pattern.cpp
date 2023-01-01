class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream op(s);
        string word;
        vector<string> ss;
        while(op >> word){
            ss.push_back(word);
        }
        unordered_map<char,string> mp;
        if(pattern.size() != ss.size()) return false;
        for(int i = 0;i < ss.size();++i){
            if(mp.find(pattern[i]) == mp.end()){
                mp[pattern[i]] = ss[i];
            }
            else{
                if(mp[pattern[i]] != ss[i]) return false;
            }
        }
        unordered_map<string,char> mp1;
        for(int i = 0;i < ss.size();++i){
            if(mp1.find(ss[i]) == mp1.end()){
                mp1[ss[i]] = pattern[i];
            }
            else{
                if(mp1[ss[i]] != pattern[i]) return false;
            }
        }
        return true;
    }
};
