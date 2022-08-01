class Solution {
    int nCr(int n, int r){
        double ans=1.0;
        for(int i=1;i<=r;i++){
            ans = ans*(n-r+i)/i;
        }
        return (int)ans;
    }
public:
    int uniquePaths(int m, int n) {
        return nCr(m+n-2, m-1);
    }
};