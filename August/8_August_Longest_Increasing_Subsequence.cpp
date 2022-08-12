class Solution {
public:
    int lengthOfLIS(vector<int>& ans) {
        vector<int> newAns;
    for (int i = 0; i < ans.size(); i++){
        if (newAns.empty() || newAns.back() < ans[i]){
            newAns.push_back(ans[i]);
        }
        else{
            int index = lower_bound(newAns.begin(), newAns.end(), ans[i]) - newAns.begin();
            newAns[index] = ans[i];
        }
    }
    return newAns.size();
    }
};






