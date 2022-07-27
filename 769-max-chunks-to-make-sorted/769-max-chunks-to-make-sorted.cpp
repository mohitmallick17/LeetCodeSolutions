class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int Max = 0, count = 0;
        
        for(int i=0;i<arr.size();i++){
            Max = max(Max, arr[i]);
            if(i == Max)count++;
        }
        return count;
    }
};