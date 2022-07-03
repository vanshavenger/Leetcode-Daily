class Solution {
      
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mh = INT_MIN;
        int mw = INT_MIN;
        for(int i = 0;i <= horizontalCuts.size();++i){
            if(i == 0){
                mh = max(mh,horizontalCuts[i]);
                mh %= mod;
                continue;
            }
            if(i == (horizontalCuts.size())){
                mh = max(mh,h - horizontalCuts[i-1]);
                mh %= mod;
                continue;
            }
            mh = max(mh,horizontalCuts[i] - horizontalCuts[i-1]);
            mh %= mod;
        }
        for(int i = 0;i <= verticalCuts.size();++i){
            if(i == 0){
                mw = max(mw,verticalCuts[i]);
                mw %= mod;
                continue;
            }
            if(i == (verticalCuts.size())){
                mw = max(mw,w - verticalCuts[i-1]);
                mw %= mod;
                continue;
            }
            mw = max(mw,verticalCuts[i] - verticalCuts[i-1]);
            mw %= mod;
        }
        return (1LL*mh*mw)%mod;
    }
};
