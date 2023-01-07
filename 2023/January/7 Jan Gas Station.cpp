class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int capacity = 0;
        int lesser = 0;
        for(int i = 0; i < gas.size();i++){
            capacity += (gas[i] - cost[i]);
            if(capacity < 0){
                lesser += capacity;
                capacity = 0;
                start = i+1;
            }
        }
        if(capacity + lesser >= 0){
            return start;
        }
        return -1;
    }
};
