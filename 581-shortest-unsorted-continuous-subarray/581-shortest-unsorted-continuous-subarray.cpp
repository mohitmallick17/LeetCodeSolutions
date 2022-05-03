class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int n=v.size();
        int mx=INT_MIN, mn=INT_MAX;
        int end=-2, start=-1;
        
        for(int i=0;i<n;i++){
            mx=max(mx, v[i]);
            if(v[i] < mx)end=i;
        }
        
        for(int i=n-1;i>=0;i--){
            mn=min(mn, v[i]);
            if(v[i] > mn)start=i;
        }
        
        return end-start+1;
    }
};