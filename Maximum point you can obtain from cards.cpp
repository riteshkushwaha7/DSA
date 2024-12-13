class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lsum = 0, rsum = 0;
        for(int i = 0; i<k; i++) lsum+=nums[i];
        int ridx = n-1;
        int maxsum = lsum;
        for(int i = k-1; i>=0; i--){
            lsum-=nums[i];
            rsum+=nums[ridx];
            ridx--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};
