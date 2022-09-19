class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        if(paths.size() == 0) return ans;
        map<string,vector<string>> mp;
        for(auto & it: paths){
            stringstream ss(it);
            string word;
            ss >> word;
            string root = word;
            root += "/";
            while(ss >> word){
                int position = word.find('(');
                mp[word.substr(position)].push_back(root + word.substr(0,position));
            }
        }
        for(auto & it : mp) if(it.second.size() >= 2) ans.push_back(it.second);
        return ans;
    }
};
