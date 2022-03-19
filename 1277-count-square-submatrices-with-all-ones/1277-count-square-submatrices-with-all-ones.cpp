class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        
        int ans = 0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j] != 0 and i!=m-1 and j!=n-1){
                    matrix[i][j] = min({matrix[i+1][j], matrix[i][j+1], matrix[i+1][j+1]}) + 1;
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};