class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long tot = 0;
        for(auto &it : cardPoints){
            tot += it;
        }
        int n = cardPoints.size();
        if(n == k){
            return tot;
        }
        int i = 0;
        int j = n-k;
        long sum = 0;
        for(int i = 0;i < j;i++){
            sum += cardPoints[i];
        }
        long ans = tot - sum;
        while(j < n){
            sum -= cardPoints[i++];
            sum += cardPoints[j++];
            ans = max(ans,tot - sum);
            
        }
        return ans;
    }
};
