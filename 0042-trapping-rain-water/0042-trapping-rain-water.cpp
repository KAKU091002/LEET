class Solution {
private:
    void calculateTrappedWater(const vector<int>& height, int& total_water) {
        int n = height.size();
        if (n == 0) return;

        int max_left_so_far = 0;
        int max_right_so_far = 0;
        total_water = 0;

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= max_left_so_far) {
                    max_left_so_far = height[left];
                } else {
                    total_water += max_left_so_far - height[left];
                }
                left++;
            } else {
                if (height[right] >= max_right_so_far) {
                    max_right_so_far = height[right];
                } else {
                    total_water += max_right_so_far - height[right];
                }
                right--;
            }
        }
    }

public:
    int trap(vector<int>& height) {
        int total_water = 0;
        calculateTrappedWater(height, total_water);
        return total_water;
    }
};