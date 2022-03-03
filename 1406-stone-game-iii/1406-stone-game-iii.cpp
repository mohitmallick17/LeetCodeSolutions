class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        int n=v.size();
        int next1=0, next2=0, next3=0;
        int i=n-1;
        
        while(i>=0){
            int ans = v[i] - next1;
            if(i+1 < n)
               ans = max(ans,  v[i]+v[i+1]-next2);
            if(i+2 < n)
            ans = max(ans, v[i]+v[i+1]+v[i+2]-next3);
            
            next3=next2;
            next2=next1;
            next1=ans;
            i--;
        }
        
        int res = next1;
        if(res==0)return "Tie";
        return (res > 0) ? "Alice" : "Bob";
    }
};