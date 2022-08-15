class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
        vector<double> cur(n+1, 0);
        
        cur[0]=1;
        for(int j=1;j<=n;j++)cur[j]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=n;j>=1;j--){
        
                if(s[i-1] == t[j-1])
                    cur[j]=cur[j-1] + cur[j];
                else
                    cur[j]=cur[j];
            }
        }
        return cur[n];
    }
};