class Solution {
public:
    int numSteps(string s) {
        int steps=0, carry=0;
        
        for(int i=s.size()-1;i>0;i--){
            int d = s[i]-'0';
            if((d + carry)%2 == 0){
                steps++;
                if(d==1 and carry==1)carry=1;
                else carry=0;
            }else{
                steps+=2;
                carry=1; // why? bcoz 
            }
        }
        return steps+carry;
    }
};