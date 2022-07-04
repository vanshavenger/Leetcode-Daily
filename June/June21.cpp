class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 1;i < n;i++){
            if(heights[i-1] >= heights[i]){
                continue;
            }
            int diff = heights[i] - heights[i-1];
            pq.push(diff);
            if(pq.size() > ladders){
                int br = pq.top();
                pq.pop();
                if(bricks >= br){
                    bricks-=br;
                }else{
                    return i-1;
                }
                   
            }
        }
        return n-1;
    }
};
