// Dynamic Programming

class Solution {
public:
    int solve(vector<vector<int>> &dp, int i, int j, string &s)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        dp[i][j] = 0;
        if (i == j)
        {
            return dp[i][j] = 1;
        }
        if (j - i == 1)
        {
            if (s[i] == s[j])
            {
                return dp[i][j] = 1;
            }
            else
            {
                return dp[i][j];
            }
        }
        if (s[i] == s[j] && solve(dp, i + 1, j - 1, s) == 1)
        {
            return dp[i][j] = 1;
        }
        return dp[i][j];
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        int max_len = 0;
        int starting_index = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                solve(dp, i, j, s);
                if (dp[i][j] == 1)
                {
                    if (j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
    
};
