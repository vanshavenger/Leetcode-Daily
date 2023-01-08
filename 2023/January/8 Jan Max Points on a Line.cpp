class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        double op = 1e4+10;
        int mx = 0,x1,x2,y1,y2;
        double slop;
        unordered_map<double,int> mp;
        for(int i = 0 ;i < points.size()-1;i++){
            x1 = points[i][0];
            y1 = points[i][1];
            mp.clear();
            for(int j = i+1;j < points.size();j++){
                x2 = points[j][0];
                y2 = points[j][1];
                if(y1 == y2){
                    mp[op]++;
                }else if(x1 == x2){
                    mp[0]++;
                }else{
                    slop = (y2 - y1)*(1.0)/(x2-x1);
                    mp[slop]++;
                }
            }
            for(auto&it : mp){
                if(it.second > mx){
                    mx = it.second;
                }
            }
        }
        
        return mx+1;

    }
};
