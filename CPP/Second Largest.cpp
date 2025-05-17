//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        int lar = INT_MIN;
        int slar = INT_MIN;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            if(lar<arr[i]){
                slar = lar;
                lar = arr[i];
            }
            
            else if(arr[i] != lar && slar < arr[i]){
                slar = arr[i];
            }
        }
        if(slar == INT_MIN)
            return -1;
        return slar;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends