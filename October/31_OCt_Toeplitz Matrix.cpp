class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i < n;i++){
            int ff = matrix[i][0];
            int x = i+1;
            int y = 1;
            while(x < n && y < m){
                if(ff != matrix[x][y]) return false;
                x++;
                y++;
            }
        }
        for(int j = 1;j < m;j++){
            int ff = matrix[0][j];
            int x = 1;
            int y = j+1;
            while(x < n && y < m){
                if(ff != matrix[x][y]) return false;
                x++;
                y++;
            }
        }
        return true;
        
    }
};
