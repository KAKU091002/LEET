class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(int index, vector<int>& nums) {
        // Base case
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[index]);
        solve(index + 1, nums);

        // Backtrack
        subset.pop_back();

        // Exclude current element
        solve(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};