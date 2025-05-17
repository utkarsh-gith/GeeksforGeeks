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

 