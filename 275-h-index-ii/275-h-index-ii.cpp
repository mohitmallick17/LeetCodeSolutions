class Solution {
public:
    int hIndex(vector<int>& v) {
        int n=v.size();
        int l=0, h=n-1;
        int ans=n;
        
        while(l <= h){
            int mid=l + (h-l)/2;
            if(v[mid] >= n-mid){
                ans=mid;
                h=mid-1;
            }else
                l=mid+1;
        }
        return n-ans;
    }
};