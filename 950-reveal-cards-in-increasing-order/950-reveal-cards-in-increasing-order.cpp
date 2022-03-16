class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n=deck.size();
        for(int i=0;i<n;i++)q.push(i);
        vector<int> res(n);
        sort(deck.begin(), deck.end());
        int i=0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            res[idx] = deck[i++];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};