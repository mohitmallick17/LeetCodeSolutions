class Solution {
    void sortArr(vector<vector<int>>& mat, int si, int sj){
        int m=mat.size(), n=mat[0].size();
        vector<int> v;
        for(int i=si, j=sj;i<m and j<n;i++,j++){
            v.push_back(mat[i][j]);
        }
        sort(v.begin(), v.end());
        for(int i=si, j=sj,idx=0;i<m and j<n;i++,j++,idx++){
            mat[i][j] = v[idx];
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        
        for(int i=0;i<m;i++)
            sortArr(mat, i, 0);
        for(int i=1;i<n;i++)
            sortArr(mat, 0, i);
        return mat;
    }
};