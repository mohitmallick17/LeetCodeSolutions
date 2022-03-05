struct player{
    int age;
    int score;
    player(int a, int s) : age(a), score(s) {}
    
    bool operator<(player& b){
        if(age==b.age)
            return score > b.score;
        return age > b.age;
    }
};
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<player> v;
        for(int i=0;i<n;i++){
            v.push_back(player(ages[i], scores[i]));
        }
        sort(v.begin(), v.end());
        
        int ans = 0;
        vector<int> dp(n);
        
        for(int i=0;i<n;i++){
            int score = v[i].score;
            dp[i]=score;
            for(int j=0;j<i;j++){
                if(v[j].score >= v[i].score){                
                    dp[i] = max(dp[i], dp[j]+score);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};