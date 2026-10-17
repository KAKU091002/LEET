class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        set<char> seen;
        for (char ch : s) {

            if (seen.find(ch) == seen.end()) {
                seen.insert(ch);
            } else {
                ans += 2;
                seen.erase(ch);
            }
        }

        if (!seen.empty()) {
            ans++;
        }

        return ans;
    }
};