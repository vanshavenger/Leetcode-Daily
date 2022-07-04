class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(int i = 0; i< s.size();i++){
            freq[s[i] - 'a']++;
        }
        priority_queue<int> pq;
        for(int i = 0;i < 26;i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }
        int ans = 0;
        while(pq.size() != 0 && pq.top() != 0){
            int curr = pq.top();
            pq.pop();
            if(pq.size() != 0 && pq.top() == curr){
                curr--;
                    ans++;
                pq.push(curr);
            }
        }
        return ans;
    }
};
