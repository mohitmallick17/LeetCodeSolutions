class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int count=m*n;
        vector<int> res;
        int sr=0, sc=0, er=m-1, ec=n-1;
        
        while(count > 0){
            for(int i=sc;i<=ec and count>0;i++){
                res.push_back(matrix[sr][i]);
                count--;
            }
            sr++;
            for(int i=sr;i<=er and count>0;i++){
                res.push_back(matrix[i][ec]);
                count--;
            }
            ec--;
            for(int i=ec;i>=sc and count>0;i--){
                res.push_back(matrix[er][i]);
                count--;
            }
            er--;
            for(int i=er;i>=sr and count>0;i--){
                res.push_back(matrix[i][sc]);
                count--;
            }
            sc++;                
        }
        return res;
    }
};