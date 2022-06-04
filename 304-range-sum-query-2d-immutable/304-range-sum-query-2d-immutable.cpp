class NumMatrix {
    int m, n;
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size() + 1, n=matrix[0].size()+1;
        v.resize(m, vector<int>(n, 0));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                v[i][j]=matrix[i-1][j-1] + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
                cout << v[i][j] << ' ';
            }
            // cout << '\n';
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++, row2++, col1++, col2++;
        return v[row2][col2] - v[row2][col1-1] - v[row1-1][col2] + v[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */