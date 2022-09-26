class DSU{
    vector<int> v;
    vector<int> rank;
public:
    DSU(int size){
        v.resize(size);
        rank.resize(size,1);
        for(int i=0;i<size;i++)v[i]=i;
    }
    int findPar(int k){
        if(k==v[k])return k;
        return v[k]=findPar(v[k]);
    }
    void union_(int a, int b){
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa==pb)return;
        if(rank[pa] > rank[pb]){
            v[pb]=pa;
        }else if(rank[pa] < rank[pb]){
            v[pa]=pb;
        }else{
            v[pb]=pa;
            rank[pa]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto &e:equations){
            if(e[1]=='='){
                dsu.union_(e[0]-'a', e[3]-'a');
            }
        }
        for(auto &e:equations){
            if(e[1]=='!'){
                if(dsu.findPar(e[0]-'a')==dsu.findPar(e[3]-'a'))return false;
            }
        }
        return true;
    }
};