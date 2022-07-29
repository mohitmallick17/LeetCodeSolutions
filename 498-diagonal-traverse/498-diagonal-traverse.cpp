class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> v[m+n-1];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        
        for(int i=0;i<m+n-1;i++){
            if((i&1) == 0)// odd idx
                reverse(v[i].begin(), v[i].end());
            for(auto &x:v[i])res.push_back(x);
        }
        return res;
    }
};