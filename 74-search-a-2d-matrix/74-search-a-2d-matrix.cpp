class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        
        int low=0, high=(m*n)-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            
            int mid_i = mid/n;
            int mid_j = mid%n;
            
            if(matrix[mid_i][mid_j] == target)
                return true;
            else if(matrix[mid_i][mid_j] > target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};