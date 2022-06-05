class Solution {
    int res=0;
    void solve(int col, int n, vector<bool> &left, vector<bool> &du, vector<bool> &dd){
        if(col == n){
            res++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(left[row]==false and dd[col+row]==false and du[n-1 + col-row]==false){
                left[row]=true, dd[col+row]=true, du[n-1 + col-row]=true;
                solve(col+1,n,left,du,dd);
                left[row]=false, dd[col+row]=false, du[n-1 + col-row]=false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<bool> left(n, false), diagUp(2*n - 1, false), diagDown(2*n - 1,false);
        solve(0, n, left, diagUp, diagDown);
        return res;
    }
};