class Solution {
public:
    int fun(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, r = 0, psum = 0, cnt = 0;
        while (r < nums.size()) { 
            psum += (nums[r] % 2); 
            while (psum > k) {
                psum -= (nums[l] % 2); 
                l++;
            }
            cnt += r - l + 1; 
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};
