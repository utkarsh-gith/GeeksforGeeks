class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> res;
        int i = 0, j = 0;
        int n1 = a.size(), n2 = b.size();

        while(i < n1 && j < n2){
            if(a[i] == b[j]){
                // Avoid duplicates in result
                if(res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                i++;
                j++;
            } else if(a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};