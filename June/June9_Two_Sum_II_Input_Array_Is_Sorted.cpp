class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> o;
        int n = numbers.size();
        int s = 0;
        int e = n-1;
        while(s < e){
            if(numbers[s] + numbers[e] == target){
                o.push_back(s+1);
                o.push_back(e+1);
                break;
            }
            else if(numbers[s] + numbers[e] > target){
                e--;
            }
            else{
                s++;
            }
        }
        return o;
    }
};
