class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(suits[0]==suits[1] and suits[0]==suits[2] and suits[0]==suits[3] and suits[0]==suits[4])return "Flush";
        
        unordered_map<int, int> s2;
        for(auto &r:ranks){
            s2[r]++;
        }
        string ans;
        for(auto &r:ranks){
            if(s2[r] >= 3)ans= "Three of a Kind";
            else if(s2[r] == 2 and ans.empty())ans= "Pair";
        }
        if(!ans.empty())return ans;
        return "High Card";
    }
};