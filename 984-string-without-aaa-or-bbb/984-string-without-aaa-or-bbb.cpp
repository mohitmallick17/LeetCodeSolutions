class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res;
        while(A+B > 0){
            int n=res.size();
            if(n >= 2 and res[n-2]=='a' and res[n-1]=='a'){
                res += 'b';
                B--;
            }else if(n >= 2 and res[n-2]=='b' and res[n-1]=='b'){
                res += 'a';
                A--;
            }else if(A >= B){
                res += 'a';
                A--;
            }else{
                res += 'b';
                B--;
            }
        }
        return res;
    }
};