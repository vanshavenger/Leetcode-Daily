class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string str;
        stringstream see(s);
        while(see >> str){
            arr.emplace_back(str);
        }
        reverse(arr.begin(),arr.end());
        string ans = "";
        for(auto & it : arr){
            ans += it;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
