class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cells = n*n;
        
        int l=0, r=n-1, u=0, d=n-1;
        
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1;
        while(cells){
            for(int i=l;i<=r and cells;i++)
                res[u][i]=val++, cells--;
            u++;
            for(int i=u;i<=d and cells;i++)
                res[i][r]=val++, cells--;
            r--;
            for(int i=r;i>=l and cells;i--)
                res[d][i]=val++, cells--;
            d--;
            for(int i=d;i>=u and cells;i--)
                res[i][l]=val++, cells--;
            l++;
        }
        return res; 
    }
};