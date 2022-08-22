class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> left(n), right(n), count(n);
        
        int candles=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='|')candles=i;
            left[i]=candles;
        }
        
        candles=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|')candles=i;
            right[i]=candles;
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='|')cnt++;
            count[i]=cnt;
        }
        
        vector<int> res;
        for(auto &q:queries){
            int l=right[q[0]];
            int r=left[q[1]];
            
            if(l==-1 or r==-1)
                res.push_back(0);
            else{
                int diff = r-l;
                if(diff > 1)
                    res.push_back(r-l+1-(count[r]-count[l]+1));
                else
                    res.push_back(0);
            }
        }
        return res;
    }
};