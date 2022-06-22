class Solution {
    int atMostKNiceSubArr(vector<int>& v, int k){
        // if(k==0)return 0;
        int res = 0;
        
        for(int s=0, e=0;e<v.size();e++){
            if(v[e]&1)k--;
            
            while(s<e and k < 0){
                if(v[s]&1)k++;
                s++;
            }
            if(k>=0)
                res += e-s+1;
        }
        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKNiceSubArr(nums, k) - atMostKNiceSubArr(nums, k-1);
    }
};