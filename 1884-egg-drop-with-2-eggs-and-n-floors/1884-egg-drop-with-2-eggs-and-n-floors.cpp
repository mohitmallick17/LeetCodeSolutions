class Solution {
public:
    int twoEggDrop(int n) {
        int m = 1;
        
        while((m * (m+1))/2 < n)
            m++;
        return m;
    }
};