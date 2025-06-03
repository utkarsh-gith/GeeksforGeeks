class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr[arr.size() - 1];
        for(int i = arr.size() - 1;i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = n;
    }
};