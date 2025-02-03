class Solution {
public:

    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        int incr = 1, decr = 1;
        for (int i = 1; i < n; i++) {
            if(nums[i]>nums[i-1]){
                incr++;
                decr = 1;
                longest = max(longest,incr);
            }
            else if(nums[i]<nums[i-1]){
                decr++;
                incr = 1;
                longest = max(longest,decr);
            }else{
                incr = 1;
                decr = 1;
            }
        }
        return longest;
    }
};
