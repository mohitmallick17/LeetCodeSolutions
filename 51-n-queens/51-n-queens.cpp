class Solution {
    vector<vector<string>> ans;
    
    void solve(int col, int n, vector<string>& board, vector<bool> &leftdiag, vector<bool>&upperdiag, vector<bool>&lowerdiag){
        
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){        
            if(leftdiag[row]==false and lowerdiag[row+col]==false and upperdiag[(n-1) + (row-col)]==false){
                board[row][col] = 'Q';
                leftdiag[row]=true, lowerdiag[row+col]=true, upperdiag[(n-1) + (row-col)]=true;
                solve(col+1, n, board, leftdiag, upperdiag, lowerdiag);
                leftdiag[row]=false, lowerdiag[row+col]=false, upperdiag[(n-1) + (row-col)]=false;
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i] = string(n, '.');
        }
        vector<bool> leftdiag(n, false), upperdiag(2*n -1, false), lowerdiag(2*n - 1, false);
        
        solve(0, n, board, leftdiag, upperdiag, lowerdiag);
        
        return ans;
    }
};