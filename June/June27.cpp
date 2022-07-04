class Solution {
public:
    int minPartitions(string n) {
        int op = 0;
        for(auto& it : n){
            if(op < (it-'0')){
                op = it-'0';
            }
        }
        return op;
    }
};
