class Solution {
    vector<int> nextDay(vector<int>& a){
        vector<int> b(8, 0);
        for(int i=1;i<7;i++)
            b[i] = (a[i-1] == a[i+1]);
        return b;
    }
    int arrToNum(vector<int>& v){
        int res=0;
        for(int i=0;i<8;i++){
            if(v[i]==1)
                res |= (1<<i);
        }
        return res;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_set<int> vis;
        bool hasCycle=false;
        
        for(int i=0;i<n;i++){
            vector<int> nxt = nextDay(cells);
            int key = arrToNum(nxt);
            if(!vis.count(key)){
                vis.insert(key);
            }else{
                hasCycle=true;
                break;
            }
            cells=nxt;            
        }
        if(hasCycle){
            int cycleLen = vis.size();
            n = n%cycleLen;
            for(int i=0;i<n;i++)
                cells = nextDay(cells);
        }
        return cells;
    }
};