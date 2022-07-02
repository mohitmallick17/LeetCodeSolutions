class Solution {
public:
    int maxArea(int h, int w, vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long amax=0, bmax=0;
        
        for(int i=0;i<A.size();i++){
            int cur = A[i] - (i==0 ? 0 : A[i-1]);
            amax = max(amax, (long long)cur);
        }
        amax = max(amax, (long long)h-A.back());
        for(int i=0;i<B.size();i++){
            int cur = B[i] - (i==0 ? 0 : B[i-1]);
            bmax = max(bmax, (long long)cur);
        }
        bmax = max(bmax, (long long)w-B.back());
        
        return (amax*bmax)%1000000007;
    }
};