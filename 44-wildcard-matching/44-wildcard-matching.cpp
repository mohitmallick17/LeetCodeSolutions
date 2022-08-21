class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<bool> prev(n+1, false), cur(n+1, false);

        prev[0]=true;
        
        for(int j=1;j<=n;j++){
            bool ans = true;
            for(int x=j;x>0;x--){
                if(p[x-1] != '*'){
                    ans=false;
                    break;
                }
            }
            prev[j] = ans;
            
        }
        
        for(int i=1;i<=m;i++){
            cur[0]=false;
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] or p[j-1]=='?')
                    cur[j] = prev[j-1];
                else if(p[j-1]=='*'){
                    cur[j] = prev[j] or cur[j-1];
                }else
                    cur[j] = false;
            }
            prev=cur;
        }
        return prev[n];
    }
};