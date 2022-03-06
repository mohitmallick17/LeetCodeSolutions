class Solution {
    bool isValid(char c, int row, int col, vector<vector<char>>& board){
        for(int i=0;i<9;i++)
            if(board[i][col]==c)return false;
        for(int j=0;j<9;j++)
            if(board[row][j]==c)return false;
        
        int row3 = (row/3) * 3;
        int col3 = (col/3) * 3;
        
        for(int i=row3;i<row3+3;i++){
            for(int j=col3;j<col3+3;j++){
                if(board[i][j]==c)return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.')continue;
                
                for(char digit='1';digit <= '9';digit++){
                    if(isValid(digit,i,j,board)){
                        board[i][j]=digit;
                        if(solve(board))
                            return true;
                        else
                            board[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};