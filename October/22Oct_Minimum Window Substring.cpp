class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }
        if(s == t){
            return s;
        }
        string output = "";
        int i = 0;
        int j = 0;
        int start = -1;
        int end = -1;
        unordered_map<char,int> mp;
        for(int i = 0;i < t.length();i++){
            mp[t[i]]++;
        }
        int count = mp.size();
        int ans = INT_MAX;
        while(j < s.length()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count--;
                }
            }
            if(count == 0){
                if((j - i + 1) < ans){
                    ans = (j - i + 1);
                    start = i;
                    end = j;
                }
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        if(mp[s[i]] <= 0){
                            mp[s[i]]++;
                            if(mp[s[i]] > 0){
                                count++;
                            }
                        }
                    }
                    i++;
                    if((j - i + 1) < ans && count == 0){
                        start = i;
                        end = j;
                        ans = (j - i + 1);
                    }
                    
                }
            }
            j++;
        }
        if(start == -1 && end == -1){
            return "";
        }
        for(int i = start; i <= end;i++){
            output+=s[i];
        }
        return output;
    }
};
