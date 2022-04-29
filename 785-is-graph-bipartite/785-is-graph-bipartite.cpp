class Solution {
    bool solve(int src, vector<vector<int>>& graph, vector<int> &colors){
        if(colors[src]==-1)colors[src]=0;
        
        for(int nbr:graph[src]){
            if(colors[nbr]==-1){
                colors[nbr] = 1-colors[src];
                if(!solve(nbr, graph, colors))
                    return false;
            }else if(colors[nbr]==colors[src])
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n, -1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1 and !solve(i, graph, colors))
                return false;
        }
        return true;
    }
};