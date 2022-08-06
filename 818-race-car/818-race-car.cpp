class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q; // queue: position, speed
        q.push({0,1});
        unordered_map<int, unordered_set<int>> visited;
        visited[0].insert(1);
        
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto front=q.front();
                q.pop();
                int curPos = front.first;
                int curSpeed = front.second;
                
                if(curPos == target)return steps;
                
                // A
                int nextPos = curPos + curSpeed;
                int nextSpeed = curSpeed*2;
                
                if(visited[nextPos].find(nextSpeed)==visited[nextPos].end() and abs(target-nextPos) < target){
                    visited[nextPos].insert(nextSpeed);
                    q.push({nextPos, nextSpeed});
                }
                // R
                nextPos = curPos;
                nextSpeed = (curSpeed < 0 ? 1 : -1);
                
                if(visited[nextPos].find(nextSpeed)==visited[nextPos].end() and abs(target-nextPos) < target){
                    visited[nextPos].insert(nextSpeed);
                    q.push({nextPos, nextSpeed});
                }
            }
            steps++;
        }
        return -1;
    }
};