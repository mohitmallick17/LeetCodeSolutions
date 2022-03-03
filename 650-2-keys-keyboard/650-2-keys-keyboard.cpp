class Solution {
public:
    int minSteps(int n) {
        long long ans = 0;
        
        for(long long i=2;i*i <= (long long)n;){
            if(n % i == 0){
                ans += i;
                n /= i;
            }else
                i++;
        }
        if(n > 1)
            ans += n;
        return ans;
    }
};