class Solution {
public:
    vector<int> ans;
    void sol(int n,int k,int num){
        if(n == 0){
            ans.emplace_back(num);
            return;
        }
        int pre = num%10;
        if(k != 0 && (pre - k) >= 0) sol(n-1,k,num*10 + (pre - k));
        if((pre + k) <= 9) sol(n-1,k,num*10+ (pre+k));
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int num = 9;num >= 1;--num){
            sol(n-1,k,num);
        }
        return ans;
    }
};
