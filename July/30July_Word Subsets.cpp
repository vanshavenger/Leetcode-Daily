class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> temp(26);
        vector<int> mx(26,0);
        for(auto&it : words2){
            fill(temp.begin(),temp.end(),0);
            for(auto&i : it){
                temp[i - 'a']++;
                mx[i-'a'] = max(mx[i-'a'],temp[i - 'a']);
            }
        }
        bool flag;
        for(auto & it : words1){
            fill(temp.begin(),temp.end(),0);
            for(auto& i : it) temp[i - 'a']++;
            flag = true;
            for(int i = 0;i < 26;i++){
                if(temp[i] < mx[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.emplace_back(it);
        }
        return ans;
    }
};
