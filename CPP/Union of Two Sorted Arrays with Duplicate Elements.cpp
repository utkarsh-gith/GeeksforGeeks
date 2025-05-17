//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        int n = a.size();
        int m = b.size();
        
        vector<int> result;
        
        int i=0, j=0;
        
        while(i<n && j<m){
            
            if(i>0 && a[i] == result.back()){
                i++;
                continue;
            }
            if(j>0 && b[j] == result.back()){
                j++;
                continue;
            }
            
            if(a[i] < b[j]){
                result.push_back(a[i]);
                i++;
            }
            else if(a[i] > b[j]){
                result.push_back(b[j]);
                j++;               
            }
            else{
                result.push_back(a[i]);
                i++;
                j++;

            }
        }
        
        while(i<n){
             if(i>0 && a[i] == result.back()){
                i++;
                continue;
            }
            result.push_back(a[i]);
            i++;
        }
        while(j<m){
            if(j>0 && b[j] == result.back()){
                j++;
                continue;
            }
            result.push_back(b[j]);
            j++;
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends