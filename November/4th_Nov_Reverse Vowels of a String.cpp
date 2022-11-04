class Solution {
public:
    bool check(char& a){
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
        if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') return true;
        return false;
    }
    string reverseVowels(string s) {
        vector<char> vow;
        for(auto & it : s){
            if(check(it)) vow.emplace_back(it);
        }
        int i = vow.size() - 1;
        for(auto & it : s){
            if(check(it)) it = vow[i--];
        }
        return s;
    }
};
