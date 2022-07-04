class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        int n = target.size();
        for(int i = 0;i < n;i++){
            pq.push(target[i]);
            sum += target[i];
        }
        if(pq.top() == 1){
            return true;
        }
        while(pq.top() != 1){
            long long mx = pq.top();
            sum -= mx;
            if(sum == 0 || sum >= mx){
                return false;
            }
            long long old = mx%sum;
            if(sum != 1 && old == 0) return false;
            pq.pop();
            sum += old;
            pq.push(old);
        }
        return true;
    }
};
