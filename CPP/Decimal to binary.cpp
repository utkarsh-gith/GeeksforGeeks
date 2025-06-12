class Solution {
  public:
    string decToBinary(int n) {
        string res = "";
        
        while(n > 0){
            res = (n % 2 == 0 ? '0' : '1') + res;
            n /= 2;
        }
        
        return res;
    }
};