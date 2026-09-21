class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(vector<int>& nums, int low, int high) {
        if (low > high)
            return nullptr;

        int mid = low + (high - low) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, low, mid - 1);
        root->right = build(nums, mid + 1, high);

        return root;
    }
};