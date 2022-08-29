class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)return 1/x * myPow(1/x, -(n+1));
        if(n==0)return 1.0;
        
        if(n & 1) //odd n
            return x * myPow(x*x, n/2);
        else // even n
            return myPow(x*x, n/2);
    }
};