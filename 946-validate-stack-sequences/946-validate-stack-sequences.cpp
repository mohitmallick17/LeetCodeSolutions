class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        
        for(int &x:pushed){
            pushed[i] = x;
            i++;
            
            while(i > 0 and pushed[i-1] == popped[j])
                i--, j++;
        }
        return i==0;
    }
};