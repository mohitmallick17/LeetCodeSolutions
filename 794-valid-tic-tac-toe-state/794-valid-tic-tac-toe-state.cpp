class Solution {
    bool checkWinner(vector<string>& board, char key){
        for(int i=0;i<3;i++){
            // check row wise
            if(board[i][0]==key and board[i][1]==key and board[i][2]==key)
                return true;
            // check column wise
            if(board[0][i]==key and board[1][i]==key and board[2][i]==key)
                return true;
        }
        // left diagonal
        if(board[0][0]==key and board[1][1]==key and board[2][2]==key)
            return true;
        // right diagonal
        if(board[0][2]==key and board[1][1]==key and board[2][0]==key)
            return true;
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int xc=0, oc=0;
        for(string &s:board){
            for(char &c:s){
                if(c=='X')xc++;
                else if(c=='O') oc++;
            }
        }
        if(oc > xc)return false; // moves by p2 > p1. Invalid at any given state
        
        bool p1 = checkWinner(board, 'X'); // check if player1 wins
        bool p2 = checkWinner(board, 'O'); // check if player2 wins
        
        // both player1 and player2 winners. Imvalid
        if(p1 and p2)return false;
        // player1 wins: moves by player2: p1-1
        if(p1)return oc==xc-1;
        // player2 wins: moves by player1: p2
        if(p2)return xc==oc;
        
        // draw. so player1 can either have moves either = p2 or p2+1
        return xc-oc <= 1;
    }
};