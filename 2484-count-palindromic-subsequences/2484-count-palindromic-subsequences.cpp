class Solution {
public:
    int countPalindromes(string s) {
        int n=s.size();
        int prefix[n+1][10][10], suffix[n+1][10][10];
        memset(prefix, 0, sizeof prefix);
        memset(suffix, 0, sizeof suffix);
        int count[10] = {0};
        
        for(int i=0;i<n;i++){
            int d = s[i] - '0';
            
            if(i > 0){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        prefix[i][j][k] = prefix[i-1][j][k];
                        if(k == d)prefix[i][j][k] += count[j];
                    }
                }
            }
            count[d]++;
        }
        memset(count, 0, sizeof count);
        
        for(int i=n-1;i>=0;i--){
            int d = s[i] - '0';
            
            if(i < n-1){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        suffix[i][j][k] = suffix[i+1][j][k];
                        if(k == d)suffix[i][j][k] += count[j];
                    }
                }
            }
            count[d]++;
        }
        
        long long res = 0, mod = 1e9 + 7;
        
        for(int i=2;i<n-2;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    res = (res + (long long)prefix[i-1][j][k] * suffix[i+1][j][k])%mod;
                }
            }
        }
        return res;
    }
};