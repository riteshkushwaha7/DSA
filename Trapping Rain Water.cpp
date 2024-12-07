


class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        
        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], nums[i]);
        }

        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], nums[i]);
        }

        int store = 0;
        for (int i = 0; i < n; i++) {
            int mini = min(left[i], right[i]);
            if (mini > nums[i]) {
                store += mini - nums[i];
            }
        }
        return store;
    }
};
