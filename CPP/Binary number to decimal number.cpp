class Solution {
  public:
    int binaryToDecimal(string &b) {
        int res = 0;
        for(char& c : b){
            int a = c - '0';
            res = res * 2 + a;
        }
        return res;
    }
};