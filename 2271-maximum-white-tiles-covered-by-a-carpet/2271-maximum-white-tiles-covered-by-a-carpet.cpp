class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int res=0, j=0, cur=0;
        sort(tiles.begin(), tiles.end());
        for(int i=0;i<tiles.size() and res<carpetLen;){
            if(i==j or tiles[j][0]+carpetLen > tiles[i][1]){
                // start of range / can fully cover i'th tile
                cur += min(carpetLen, tiles[i][1]-tiles[i][0]+1);
                res = max(res, cur);
                i++;
            }else{
                int partial = max(0, tiles[j][0]+carpetLen-tiles[i][0]);
                res = max(res, cur+partial);
                cur -= tiles[j][1]-tiles[j][0]+1;
                j++;
            }
        }
        return res;
    }
};