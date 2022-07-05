class Solution {
    vector<string> less_than_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
        if(num==0)return "Zero";
        string res;
        int th = 0;
        
        while(num > 0){
            // process 3 digits at once
            if(num%1000 != 0)
                res = solve(num%1000) + thousands[th] + " " + res;
            num /= 1000;
            th++;
        }
        return trim(res);
    }
    string solve(int n){
        if(n==0)return "";
        else if(n < 20)return less_than_20[n] + " ";
        else if(n<100)return tens[n/10] + " " + solve(n%10);
        else return less_than_20[n/100] + " Hundred " + solve(n%100);
    }
    string trim(string &s){
        int i=s.size()-1;
        while(i>0 and s[i]==' ')i--;
        return s.substr(0, i+1);
    }
};