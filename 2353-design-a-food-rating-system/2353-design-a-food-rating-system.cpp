class FoodRatings {
    unordered_map<string, string> f2c;
    unordered_map<string, int> f2r;
    unordered_map<string, set<pair<int, string>>> r;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            f2c[foods[i]]=cuisines[i];
            f2r[foods[i]]=ratings[i];
            
            r[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int prevR = f2r[food];
        string &c = f2c[food];
        r[c].erase({-prevR, food});
        r[c].insert({-newRating, food});
        f2r[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return (*r[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */