class Solution {
public:

    bool check(TreeNode* left, TreeNode* right) {

        // Both are NULL
        if (left == NULL && right == NULL)
            return true;

        // One is NULL
        if (left == NULL || right == NULL)
            return false;

        // Values are different
        if (left->val != right->val)
            return false;

        // Mirror comparison
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL)
            return true;

        return check(root->left, root->right);
    }
};