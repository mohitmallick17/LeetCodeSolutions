class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int l=0, h=v.size()-1;
        
        while(l < h){
            int s=v[l]+v[h];
            if(s==t)return {l+1, h+1};
            else if(s > t)h--;
            else l++;
        }
        return {};
    }
};