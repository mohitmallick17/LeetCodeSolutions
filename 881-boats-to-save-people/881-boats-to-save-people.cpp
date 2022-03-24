class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats=0;
        int low=0, high=people.size()-1;
        while(low <= high){
            if(people[low] + people[high] <= limit)
                low++, high--;
            else
                high--;
            boats++;
        }
        return boats;
    }
};