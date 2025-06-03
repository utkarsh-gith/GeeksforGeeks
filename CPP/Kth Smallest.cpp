class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>>  pq;
        for(int& a : arr){
            pq.push(a);
        }
        for (int i = 1; i < k; ++i) {
            pq.pop();
        }
        return pq.top();
    }
};