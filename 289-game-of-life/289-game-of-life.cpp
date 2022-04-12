class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Meaning os states
        // 0 remains 0
        // 1 remains 1
        // 0 -> 1 = 3 (we are storing 2 infos here: 1st this node earlier was 0 but now is 1)
        // 1 -> 0 = 4 (we are storing 2 infos here: 1st this node earlier was 1 but now is 0)
        int m=board.size(), n=board[0].size();
        
        vector<int> dirs{-1, 0, 1};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // count # of ones
                int ones = 0;
                
                for(int d1:dirs){
                    for(int d2:dirs){
                        // pruning: if ones >= 4, break as (i, j) it is already invalidated by overpopulation
                        if(ones > 3)break;
                        
                        // same as current node: skip
                        if(d1==0 and d2==0)continue;
                        
                        int x=i+d1, y=j+d2; // x,y are the neighbor axis
                        // if isValid and my neighbor is 1 (or was before, state 4), increment # of ones
                        if(x>=0 and y>=0 and x<m and y<n and (board[x][y]==1 or board[x][y]==4))
                            ones++;
                    }
                }
                // if cur node is 0, we can make it if we have exactly 3 one neighbors
                if(board[i][j]==0){
                    if(ones==3)board[i][j]=3;
                }else if(board[i][j]==1){
                    // if cur node is 1, it can be invalidated by following cases
                    if(ones < 2)board[i][j]=4; // die out of underpopulation
                    else if(ones > 3)board[i][j]=4; // die out of overpopulation
                    // otherwise lives
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==3) // state 3: 0->1. finally make it 1
                    board[i][j]=1;
                else if(board[i][j]==4) // state 34: 1->0. finally make it 0
                    board[i][j]=0;
            }
        }
    }
};