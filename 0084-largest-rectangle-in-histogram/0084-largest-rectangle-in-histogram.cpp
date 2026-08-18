class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxA = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxA = max(maxA, height * width);
            }

            st.push(i);
        }

        return maxA;
    }
};