class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 1 -> 0 = 4
        // 0 -> 1 = 3
        int m=board.size(), n=board[0].size();
        
        vector<int> dirs{-1, 0, 1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ones = 0;
                // bool flag = (i==0 and j==2);
                for(int d1:dirs){
                    for(int d2:dirs){
                        if(d1==0 and d2==0)continue;
                        int x=i+d1, y=j+d2;
                        // if(flag)cout << x << ' ' << y << " : ";
                        if(x>=0 and y>=0 and x<m and y<n and (board[x][y]==1 or board[x][y]==4)){
                            // if(flag)cout << x << ' ' << y << ", ";
                            ones++;
                        }
                        // if(flag)cout << '\n';
                        if(ones > 3)break;
                    }
                }
                // cout << i << ' ' << j << " - " << ones << '\n';
                if(board[i][j]==0){
                    if(ones==3)board[i][j]=3;
                }else if(board[i][j]==1){
                    if(ones < 2)board[i][j]=4; // die out of underpopulation
                    else if(ones > 3)board[i][j]=4; // die out of overpopulation
                    // otherwise lives
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==3)
                    board[i][j]=1;
                else if(board[i][j]==4)
                    board[i][j]=0;
            }
        }
        
    }
};