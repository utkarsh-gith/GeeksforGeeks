class Solution
{
public:
    bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &mat, int n)
    {
        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] != 1 && mat[x][y] == 1)
        {
            return true;
        }
        return false;
    }
    void helper(int x, int y, vector<vector<int>> &mat, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // DOWN
        if (isSafe(x + 1, y, visited, mat, n))
        {
            helper(x + 1, y, mat, n, ans, visited, path + 'D');
        }
        // LEFT
        if (isSafe(x, y - 1, visited, mat, n))
        {
            helper(x, y - 1, mat, n, ans, visited, path + 'L');
        }
        // RIGHT
        if (isSafe(x, y + 1, visited, mat, n))
        {
            helper(x, y + 1, mat, n, ans, visited, path + 'R');
        }
        // UP
        if (isSafe(x - 1, y, visited, mat, n))
        {
            helper(x - 1, y, mat, n, ans, visited, path + 'U');
        }

        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {

        int n = mat.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        string path = "";

        if (mat[0][0] == 0)
        {
            return {};
        }
        helper(0, 0, mat, n, ans, visited, path);

        return ans;
    }
};