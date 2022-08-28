class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string cur;
        int degree = 1; // root has no parent so imaginary degree 1
        while(getline(ss, cur, ',')){
            degree--; // reduce 1 degree for parent----node edge
            if(degree < 0)return false;
            if(cur != "#")degree+=2; // if not null, have out degree of 2
        }
        return degree==0;
    }
};