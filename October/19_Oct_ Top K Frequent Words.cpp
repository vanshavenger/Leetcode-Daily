class Solution {
     private:
    struct Comp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto& it : words) mp[it]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,Comp> pq;
        for(auto& it : mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> ans;
        while(pq.size() != 0){
            string op = pq.top().second;
            ans.emplace_back(op);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
