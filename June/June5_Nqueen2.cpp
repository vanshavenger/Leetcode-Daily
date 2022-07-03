class Solution {
public:
    vector<vector<string>> ans;
    
    
    
    
    bool isValid(vector<string>& board,int row,int col,int n){
        // Row Check;
        for(int i = row;i >= 0;i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = col;i >= 0;i--){
            if(board[row][col] == 'Q'){
                return false;
            }
        }
        for(int i = row,j = col;i >= 0 && j < n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row,j = col;i >= 0 && j >= 0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    
    void solve(int n,vector<string>& board, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i < n;i++){
            if(isValid(board,row,i,n)){
                board[row][i] = 'Q';
                solve(n,board,row+1);
                board[row][i] = '.';
            }
        }
    }
       
    int totalNQueens(int n) {
        vector<string> board;
        string str(n,'.');
        for(int i = 0;i < n;i++){
            board.push_back(str);
        }
        int row = 0;
        solve(n,board,row);
        return ans.size();
    }
};
