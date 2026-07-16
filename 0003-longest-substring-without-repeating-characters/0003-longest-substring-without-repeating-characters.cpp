class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>x;
        int l=0;
        int res=0;
        for(int r=0;r<s.length();r++)
        {
            while(x.count(s[r]))
            {
                x.erase(s[l]);
                l++;
            }
            x.insert(s[r]);
            res=max(res,r-l+1);
        }
        return res;
    }
};