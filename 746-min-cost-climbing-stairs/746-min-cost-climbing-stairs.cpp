class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        int n2=0;
        int n1=cost.back();
        
        for(int i=n-2;i>=0;i--){
            int cur = min(n1, n2) + cost[i];
            n2=n1;
            n1=cur;
        }
        return min(n1, n2);
    }
};