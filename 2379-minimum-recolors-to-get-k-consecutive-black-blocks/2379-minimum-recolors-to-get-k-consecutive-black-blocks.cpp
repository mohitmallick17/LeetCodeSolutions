class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=k, b=0;
        for(int i=0;i<blocks.size();i++){
            if(blocks[i]=='B')b++;
            if(i >= k and blocks[i-k]=='B')b--;
            ans = min(ans, k-b);
        }
        return ans;
    }
};