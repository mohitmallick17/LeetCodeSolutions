class Solution {
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeap(int y){
        return y%4==0 and (y%100 != 0 or y%400==0);
    }
public:
    int dayOfYear(string dt) {
        int y = stoi(dt.substr(0,4)), m=stoi(dt.substr(5,2)), d=stoi(dt.substr(8));
        if(m>2 and isLeap(y))d++;
        m--;
        // cout << d << '\n';
        while(m > 0){
            d += days[m-1];
            m--;
        }
        return d;
    }
};