class Solution {
    // count of elements in matrix havin value <= val
    int getFloorCount(vector<vector<int>>& matrix, int val){
        int n=matrix.size();
        int i=n-1, j=0;
        int cnt=0;
        while(i>=0 and j<n){
            if(matrix[i][j] > val)i--;
            else{
                cnt += i+1;
                j++;
            }
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans=0, n=matrix.size();
        int low=matrix[0][0], high=matrix[n-1][n-1];
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int cnt = getFloorCount(matrix, mid);
            if(cnt < k)
                low=mid+1;
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};