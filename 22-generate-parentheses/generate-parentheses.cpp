class Solution {
public:
    vector<string> ans;

    void solve(string &current, int open, int close, int n)
    {
        if(current.length() == 2 * n)
        {
            ans.push_back(current);
            return;
        }

        // Choose '('
        if(open < n)
        {
            current.push_back('(');

            solve(current, open + 1, close, n);

            current.pop_back();        // Undo
        }

        // Choose ')'
        if(close < open)
        {
            current.push_back(')');

            solve(current, open, close + 1, n);

            current.pop_back();        // Undo
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string current = "";

        solve(current, 0, 0, n);

        return ans;
    }
};