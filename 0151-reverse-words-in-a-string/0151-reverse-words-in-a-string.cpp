class Solution {
    void reverseW(int s, int e, string& str){
        while(s < e){
            swap(str[s], str[e]);
            s++, e--;
        }
    }
    void removeSpaces(string &str){
        int s=0, e=str.size()-1, orig=0;
        
        while(s <= e && str[s]==' ')s++;
        while(s <= e && str[e]==' ')e--;
        
        while(s <= e){
            if(str[s] == ' '){
                // trim all spaces
                str[orig] = ' ';
                orig++;
                while(s<=e && str[s]==' ')s++;
            }else{
                str[orig] = str[s];
                s++;
                orig++;
            }
        }
        str.erase(orig);
    }
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n=s.size();
        for(int i=0;i<n;){
            if(s[i] != ' '){
                int j=i;
                bool flag=false;
                while(j<n && s[j] != ' '){
                    j++;
                    flag=true;
                }
                if(flag)j--;
                reverseW(i, j, s);
                i=j+1;
            }else
                i++;
        }
        removeSpaces(s);
        return s;
    }
};