class Solution {
public:
    bool is(string& word,string&s){
        int pos = 1;
        int i = s.find(word[0]);
        if(i == -1){
            return false;
        }
        
        while(pos < word.size()){
            i = s.find(word[pos],i+1);
            if(i == -1){
                return false;
            }
            pos++;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int c = 0;
        for(auto& it : words){
            if(is(it,s)){
                c++;
            }
        }
        return c;
    }
};
