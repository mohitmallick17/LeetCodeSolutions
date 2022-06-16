class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        int carry = 0;
        
        for(int bit=0;bit<32;bit++){
            int b1=(a>>bit)&1;
            int b2=(b>>bit)&1;
            
            if(b1+b2+carry == 0){
                // bit is 0, nothing to do
            }else if(b1+b2+carry == 1){
                res |= (1<<bit);
                carry=0;
            }else if(b1+b2+carry == 2){
                // let this bit = 0
                // and carry = 1
                carry=1;
            }else{
                // b1+b2+carry = 3
                // set this bit
                // and set carry
                res |= (1<<bit);
                carry=1;
            }
        }
        return res;
    }
};