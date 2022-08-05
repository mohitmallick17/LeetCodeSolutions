class Solution {
public:
    int compress(vector<char>& chars) {
        int write_idx = 0;
        int n=chars.size();
        for(int i=0;i<n;i++){
            char cur = chars[i];
            int len = 0;
            while(i<n and chars[i]==cur)i++, len++;
            i--;
            chars[write_idx++]=cur;
            if(len>1){
                string num = to_string(len);
                for(char &ch:num)chars[write_idx++]=ch;
            }
        }
        // chars.erase(chars.begin()+write_idx, chars.end());
        return write_idx;
    }
};