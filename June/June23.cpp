class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& a, vector<int>& b){
            if(a[1] == b[1]){
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int sum = 0;
        for(auto &it : courses){
            pq.push(it[0]);
            sum += it[0];
            if(sum > it[1]){
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
