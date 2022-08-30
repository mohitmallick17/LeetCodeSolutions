class Solution {
    int gcd(int a, int b){
        if(b==0)return a;
        return gcd(b, a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n <= 2)return n;
        int res=0;
        unordered_map<int, unordered_map<int, int>> mp;
        
        for(int i=0;i<n;i++){
            int overlaps=0;
            int mx=0;
            mp.clear();
            for(int j=i+1;j<n;j++){
                int x=points[j][0]-points[i][0], y=points[j][1]-points[i][1];
                
                if(x==0 and y==0){
                    overlaps++;
                    continue;
                }
                int g=gcd(x,y);
                if(g != 0){
                    x /= g;
                    y /= g;
                }
                mp[x][y]++;
                mx=max(mx, mp[x][y]);
            }
            res=max(res, mx+1+overlaps);
        }
        return res;
    }
};