class Solution {
    int solve(int col_idx, vector<unordered_set<int>> &ones, vector<vector<int>>& mat, int cols){
        if(col_idx == mat[0].size() or cols==0){
            int res=0;
            for(int i=0;i<ones.size();i++){
                if(ones[i].empty()){
                    // cout << i << '\n';
                    res++;
                }
            }
            return res;
        }
        // skip
        int ans = solve(col_idx+1, ones, mat, cols);
        
        vector<int> del;
        for(int i=0;i<mat.size();i++){
            if(ones[i].find(col_idx) != ones[i].end()){
                ones[i].erase(col_idx);
                del.push_back(i);
            }
        }
        ans = max(ans, solve(col_idx+1, ones, mat, cols-1));
        for(int i=0;i<del.size();i++){
            ones[del[i]].insert(col_idx);
        }
        return ans;
    }
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m=mat.size(), n=mat[0].size();
        vector<unordered_set<int>> ones(m);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)ones[i].insert(j);
            }
        }
//         for(int i=0;i<ones.size();i++){
//             for(auto &x:ones[i])
//                 cout << x << ' ';
            
//             cout << '\n';
//         }
        return solve(0,ones,mat,cols);
    }
};