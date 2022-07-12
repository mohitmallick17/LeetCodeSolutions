class Solution {
    bool solve(int i, vector<int>& matchsticks, vector<int> &sides, int mx){
        if(i==matchsticks.size())return true;
        
        for(int m=0;m<4;m++){
            if(sides[m] + matchsticks[i] > mx)continue;
            int n;
            for(n=m-1;n>=0;n--){
                if(sides[m]==sides[n])break;
            }
            if(n != -1)continue;
            sides[m] += matchsticks[i];
            if(solve(i+1,matchsticks,sides,mx))
                return true;
            sides[m] -= matchsticks[i];   
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int &m:matchsticks)
            sum+=m;
        if(sum%4 != 0)return false;
        sum/=4;
        for(int &m:matchsticks){
            if(m > sum)return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);
        return solve(0,matchsticks,sides,sum);
    }
};