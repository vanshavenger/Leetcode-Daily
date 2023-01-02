class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(int i = 0;i < word.size();i++){
            if(word[i] >= 65 && word[i] <= 90) cap++;
        }
        if(cap == 0 || cap == word.size()) return true;
        if(cap == 1 && word[0] >= 65 && word[0] <= 90) return true;
        return false;
    }
};
