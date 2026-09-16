class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }

            last[nums[i]] = i;
        }

        int degree = 0;

        for (auto it : freq) {
            degree = max(degree, it.second);
        }

        int ans = nums.size();

        for (auto it : freq) {
            int num = it.first;

            if (freq[num] == degree) {
                int length = last[num] - first[num] + 1;
                ans = min(ans, length);
            }
        }

        return ans;
    }
};