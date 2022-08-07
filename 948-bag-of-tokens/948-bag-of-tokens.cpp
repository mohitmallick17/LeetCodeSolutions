class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        sort(tokens.begin(), tokens.end());
        int start=0, end=tokens.size()-1;
        int ans=0;
        while(start <= end){
            if(power >= tokens[start]){
                score++;
                power -= tokens[start];
                start++;
                ans = max(ans, score);
            }else if(score >= 1){
                power += tokens[end];
                end--;
                score--;
            }else
                break;
        }
        return ans;
    }
};