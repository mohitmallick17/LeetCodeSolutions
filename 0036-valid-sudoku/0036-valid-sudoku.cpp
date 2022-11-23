class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')continue;
                if(!s.insert(to_string(board[i][j] - '0') + " row " + to_string(i)).second || 
                   !s.insert(to_string(board[i][j] - '0') + " col " + to_string(j)).second || 
                   !s.insert(to_string(board[i][j] - '0') + " block " + to_string(i/3) + " " + to_string(j/3)).second
                  )return false;
            }
        }
        return true;
    }
};