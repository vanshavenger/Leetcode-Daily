class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = -1;
        int start = -1;
        int end = -1;
        int l,r;
        for(int i = 0;i < s.size();i++){
            l = i;
            r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                int len = r - l + 1;
                if(len > maxi){
                    maxi = len;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while(r < s.size() && l >= 0 && s[l] == s[r]){
                int len = r - l + 1;
                if(len > maxi){
                    maxi = len;
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        string ans = "";
        for(int i = start;i <= end;i++){
            ans += s[i];
        }
        return ans;
    }
};
