class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string op = s;
            for(int i = 0;i < s.size();i++){
                rotate(s.begin(),s.begin() + 1,s.end());
                op = min(op,s);
            }
            return op;
        }
        sort(s.begin(),s.end());
        return s;
    }
};
