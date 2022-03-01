class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int count = 0;
        int n=clips.size();
        for(int i=0, start=0, end=0;start<time;count++){
            while(i<n and clips[i][0] <= start){
                end = max(end, clips[i][1]);
                i++;
            }
            if(start==end)return -1;
            start=end;
        }
        return count;
    }
};