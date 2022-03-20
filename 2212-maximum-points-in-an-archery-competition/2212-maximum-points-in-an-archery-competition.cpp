class Solution {
    vector<int> res;
    int maxi;
    
    void solve(int i, int arrows, vector<int>& aliceArrow, int sum, vector<int> bob){
        if(i==aliceArrow.size() or arrows==0){
            if(maxi < sum){
                maxi = sum;
                if(arrows > 0)bob[0] += arrows;
                res = bob;
            }
            return;
        }
        
        int cost = aliceArrow[i]+1;
        if(arrows >= cost){
            bob[i] = cost;
            solve(i+1, arrows-cost, aliceArrow, sum+i, bob);
            bob[i] = 0;
            solve(i+1, arrows, aliceArrow, sum, bob);
        }else{
            solve(i+1, arrows, aliceArrow, sum, bob);
        }
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        res = vector<int>(12, 0);
        maxi=0;
        vector<int> bob(12, 0);
        solve(0 , numArrows, aliceArrows, 0, bob);
        return res;
    }
};