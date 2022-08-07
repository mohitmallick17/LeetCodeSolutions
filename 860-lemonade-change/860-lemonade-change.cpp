class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        
        for(auto &b:bills){
            if(b==5)five++;
            else if(b==10){
                ten++;
                if(five==0)return false;
                five--;
            }else{
                if(ten >= 1 and five >= 1)
                    ten--, five--;
                else if(five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};