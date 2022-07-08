class Solution {
    int getMax(string &str, char key, int k){
        int res = 0;
        int avlK=k;
        for(int s=0, e=0, cur=0;e<str.size();e++){
            cur++;
            if(str[e] != key)avlK--;
            while(avlK<0 and s<e){
                cur--;
                if(str[s] != key)avlK++;
                s++;
            }
            res = max(res, cur);
        }
        return res;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(getMax(answerKey, 'T', k), getMax(answerKey, 'F', k));
    }
};