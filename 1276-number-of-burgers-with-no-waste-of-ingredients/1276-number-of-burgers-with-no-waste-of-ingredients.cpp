class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices & 1 or tomatoSlices < 2*cheeseSlices)return {};
        int total_jumbo=0, total_small=0;
        total_small = cheeseSlices;
        tomatoSlices -= 2 * cheeseSlices;
        
        int rem = tomatoSlices/2;
        if(rem > total_small)return {};
        
        total_jumbo = rem;
        total_small -= rem;
        
        return {total_jumbo, total_small};
    }
};