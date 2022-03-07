class Solution {
    bool checkWinner(vector<string>& board, char key){
        for(int i=0;i<3;i++){
            if(board[i][0]==key and board[i][1]==key and board[i][2]==key)
                return true;
            if(board[0][i]==key and board[1][i]==key and board[2][i]==key)
                return true;
        }
        if(board[0][0]==key and board[1][1]==key and board[2][2]==key)
            return true;
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
        if(oc > xc)return false;
        // cout << 1;
        // cout << xc << ' ' << oc << '\n';
        // bool valid = //(xc >= oc) and ((xc-oc) <= 1);
        
        bool p1 = checkWinner(board, 'X');
        bool p2 = checkWinner(board, 'O');
        if(p1 and p2)return false;
        if(p1)return oc==xc-1;
        if(p2)return xc==oc;
        cout << 2;
        return xc-oc <= 1;
    }
};