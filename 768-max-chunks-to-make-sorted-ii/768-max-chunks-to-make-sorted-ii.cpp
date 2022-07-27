class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> lmax(n), rmin(n+1);
        lmax[0] = arr[0];
        for(int i=1;i<n;i++){
            lmax[i] = max(lmax[i-1], arr[i]);
        }
        rmin[n]=INT_MAX;
        for(int i=n-1;i>=0;i--){
            rmin[i] = min(rmin[i+1], arr[i]);
        }
        int count = 0;
        
        for(int i=0;i<n;i++){
            // if max of left till i, is smaller even than the min of (right+1 to n), this is a chunk
            if(lmax[i] <= rmin[i+1])count++;
        }
        return count;
    }
};