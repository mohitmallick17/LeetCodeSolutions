class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> dig;
        while(n > 0){
            dig.push_back(n % 10);
            n /= 10;
        }
        reverse(dig.begin(), dig.end());
        
        int i;
        for(i=dig.size()-2;i>=0;i--){
            if(dig[i] < dig[i+1])break;
        }
        if(i==-1)return -1;
        int j;
        for(j=dig.size()-1;j>i;j--){
            if(dig[j] > dig[i])break;
        }
        swap(dig[i], dig[j]);
        reverse(dig.begin()+i+1, dig.end());
        long long ans = 0;
        for(int i=0;i<dig.size();i++){
            ans = (ans * 10) + dig[i];
            if(ans > INT_MAX)return -1;
        }
        return ans;
    }
};