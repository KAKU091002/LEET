class Solution {
public:

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int L = height(root->left);
        if (L == -1)
            return -1;

        int R = height(root->right);
        if (R == -1)
            return -1;

        if (abs(L - R) > 1)
            return -1;

        return 1 + max(L, R);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};