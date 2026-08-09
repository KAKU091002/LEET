class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        // 1. Reverse the whole array
        reverse(nums.begin(), nums.end());

        // 2. Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // 3. Reverse the rest of the array
        reverse(nums.begin() + k, nums.end());
    
    }
};