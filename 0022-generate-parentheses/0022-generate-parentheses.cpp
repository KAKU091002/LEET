class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;

        backtrack(n, 0, 0, current, ans);

        return ans;
    }

private:
    void backtrack(int n, int open, int close,
                   string& current, vector<string>& ans) {

        // A valid combination is complete
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            current.push_back('(');

            backtrack(n, open + 1, close, current, ans);

            current.pop_back();
        }

        // Add ')'
        if (close < open) {
            current.push_back(')');

            backtrack(n, open, close + 1, current, ans);

            current.pop_back();
        }
    }
};