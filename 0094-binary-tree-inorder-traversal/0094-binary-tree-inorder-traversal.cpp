class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Go to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();
            result.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }

        return result;
    }
};