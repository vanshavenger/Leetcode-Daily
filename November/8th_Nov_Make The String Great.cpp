class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(auto & it : s){
            if(ans.size() != 0 && ((char)(it - 32) == ans.back() || (char)(it + 32) == ans.back())){
                ans.pop_back();
            }else{
                ans += it;
            }
        }
        return ans;
    }
};  
