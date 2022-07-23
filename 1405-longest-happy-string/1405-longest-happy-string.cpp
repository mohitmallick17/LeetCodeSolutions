class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa='a', char bb='b', char cc='c') {
        if(a < b)return longestDiverseString(b,a,c,bb,aa,cc);
        if(b < c)return longestDiverseString(a,c,b,aa,cc,bb);
        // here a >= b >= c
        if(b==0)return string(min(2, a), aa);
        int min_a = min(2, a);
        int min_b = (a-min_a) >= b ? 1:0; // use b if it is still 2nd largest
        
        return string(min_a, aa) + string(min_b, bb) + longestDiverseString(a-min_a, b-min_b, c, aa,bb,cc);
    }
};