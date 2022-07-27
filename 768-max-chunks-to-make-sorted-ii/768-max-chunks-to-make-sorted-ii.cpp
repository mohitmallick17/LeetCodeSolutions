class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> tmp(arr);
        sort(tmp.begin(), tmp.end());
        unordered_map<int, queue<int>> mp; // item(value): queue of index in increasing order (for O(1) pop)
        for(int i=0;i<arr.size();i++){
            mp[tmp[i]].push(i);
        }
        int Max=0, count=0;
        
        for(int i=0;i<arr.size();i++){
            Max=max(Max, mp[arr[i]].front());
            mp[arr[i]].pop();
            if(i==Max)count++;
        }
        return count;
    }
};