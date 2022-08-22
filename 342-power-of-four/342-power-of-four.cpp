class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt=0;
        int pos=-1;
        for(int i=0;i<32;i++){
            int bit = (n >> i) & 1;
            if(bit==1)cnt++, pos=i;
        }
        return n > 0 and cnt==1 and pos%2==0;
    }
};