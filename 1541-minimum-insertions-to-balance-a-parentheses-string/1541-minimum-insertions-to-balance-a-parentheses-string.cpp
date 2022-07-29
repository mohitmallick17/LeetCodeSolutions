class Solution {
public:
    int minInsertions(string s) {
        int cost = 0;
        int n=s.size();
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i] == '(')
                open++;
            else{
                if(open==0){
                    cost++; // no prev (                    
                }else{
                    open--;
                }
                if(i==n-1 or s[i+1] != ')')cost++;
                else i++;
            }
        }
        cost += 2*(open); // 2 closings for each open (
        return cost;
    }
};