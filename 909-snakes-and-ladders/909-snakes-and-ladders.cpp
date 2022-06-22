class Solution {
    pair<int, int> getCoordinates(int v, int n){
        int r = n - (v-1)/n -1;
        int c = (v-1)%n;
        if(r%2 == n%2){
            return {r, n-1-c};
        }
        return {r, c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int> q;
        q.push(1);
        // mark visited = -1
        board[n-1][0]=-2;
        int steps=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int front = q.front();
                q.pop();
                if(front == n*n)return steps;
                for(int i=1;i<=6;i++){
                    if(front+i > n*n)break;
                    auto [x, y] = getCoordinates(front+i, n);
                    if(board[x][y]==-2)continue; 
                    if(board[x][y]==-1)q.push(front+i);
                    else q.push(board[x][y]);
                    board[x][y]=-2;
                }
            }
            steps++;
        }
        return -1;
    }
};