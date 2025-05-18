// Scroll Down to see the most efficient answer

/*
Approach 1: Recursion
            Finding all the subsets that include weights less than or equal to the capacity
            and the finding maximum value among them
            This can be done using recursion (include & exclude)
    Problem: TLE
*/
class Solution {
  public:
    int solve(vector<int> &val, vector<int> &wt, int index, int W){
        if(index < 0){
            return 0;
        }
        
        int ans = 0;
        if(wt[index] <= W){
            ans = max(ans, val[index] + solve(val, wt, index - 1, W - wt[index]));
        }
        
        ans = max(ans, solve(val, wt, index - 1, W));
        return ans;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        return solve(val, wt, wt.size() - 1, W);
        
    }
};

/*
Approach 2: Recursion + Memorisation
            We can use a 2D vector with rows = size of wt vector and column = capacity + 1
            and initialise to -1
            In every recursive call if dp[index][W] != -1, then return the value
            else use recursion to find the value
*/
class Solution {
  public:
    int solveMem(vector<vector<int>> &dp, vector<int> &val, vector<int> &wt, int index, int W){
        if(index < 0){
            return 0;
        }
        
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        
        dp[index][W] = 0;
        if(wt[index] <= W){
            dp[index][W] = max(dp[index][W], val[index] + solveMem(dp, val, wt, index - 1, W - wt[index]));
        }
        
        dp[index][W] = max(dp[index][W], solveMem(dp, val, wt, index - 1, W));
        return dp[index][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(wt.size(), vector<int>(W + 1, -1));
        return solveMem(dp, val, wt, wt.size() - 1, W);
        
    }
};

/*
Approach 3:
We use a 2D DP table, where:
	•	dp[i][w] = max value that can be obtained using the first i+1 items with total weight ≤ w
Steps:
1. Create a DP table of size n × (W+1) initialized with 0, where n is the number of items.
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
2. Base Case Initialization (0th item):
	•	If wt[0] ≤ w, set dp[0][w] = val[0]
	•	Because with only the first item, you can take it if it fits.
3. Fill the DP table (loop from item 1 to n-1):

For each item i and weight capacity w:
	•	Don’t take the item: notTake = dp[i-1][w]
	•	Take the item (if wt[i] ≤ w): take = val[i] + dp[i-1][w - wt[i]]
	•	Set dp[i][w] = max(take, notTake)
4. Return dp[n-1][W] as the answer — the best value with all items and full capacity.
Why This Works:
	•	It tries all possibilities (take or skip) for each item at each weight capacity.
	•	Stores previous results to avoid recomputation (dynamic programming).
	•	Builds up from small subproblems to the final solution.
Time Complexity:
	•	O(n × W) where n is number of items, W is max capacity
Space Complexity:
	•	O(n × W) (can be reduced to O(W) with optimization)
*/
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        
        // Base case: fill first row (0th item)
        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }

        // Fill the rest of the dp table
        for (int idx = 1; idx < n; idx++) {
            for (int w = 0; w <= W; w++) {
                int notTake = dp[idx - 1][w];
                int take = 0;
                if (wt[idx] <= w) {
                    take = val[idx] + dp[idx - 1][w - wt[idx]];
                }
                dp[idx][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }
};

/*
Approach 4:
1.	Use a 1D DP array (dp) where dp[w] stores the maximum value for weight w.
2.	Initialize base case:
    •	If the first item’s weight wt[0] fits in capacity w, set dp[w] = val[0].
3.	Iterate over remaining items:
	•	For each item, create a new temp array to store the updated results.
	•	For each capacity w from 0 to W:
	•	Don’t take the item → value = dp[w]
	•	Take the item (if it fits) → value = val[idx] + dp[w - wt[idx]]
	•	Store the max of both in temp[w].
4.	After each item, update dp with temp.
5.	Return dp[W], which holds the maximum value for capacity W.
Time Complexity:
	•	O(n × W)
Space Complexity:
	•	O(W) (using 1D array)
*/

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       int n = wt.size();
        vector<int> dp(W + 1, 0);
        
        // Base case: fill first row (0th item)
        for (int w = wt[0]; w <= W; w++) {
            dp[w] = val[0];
        }

        // Fill the rest of the dp table
        for (int idx = 1; idx < n; idx++) {
            vector<int> temp(W + 1, 0);
            for (int w = 0; w <= W; w++) {
                int notTake = dp[w];
                int take = 0;
                if (wt[idx] <= w) {
                    take = val[idx] + dp[w - wt[idx]];
                }
                temp[w] = max(take, notTake);
            }
            dp = temp;
        }

        return dp[W];
    }
};

// Most Efficient Best Answer
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
       int n = wt.size();
        vector<int> dp(W + 1, 0);
        
        // Base case: fill first row (0th item)
        for (int w = wt[0]; w <= W; w++) {
            dp[w] = val[0];
        }

        // Fill the rest of the dp table
        for (int idx = 1; idx < n; idx++) {
            for (int w = W; w >= 0; w--) {
                int notTake = dp[w];
                int take = 0;
                if (wt[idx] <= w) {
                    take = val[idx] + dp[w - wt[idx]];
                }
                dp[w] = max(take, notTake);
            }
        }

        return dp[W];
    }
};