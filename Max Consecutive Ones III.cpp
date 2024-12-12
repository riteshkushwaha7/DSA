class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int l = 0, r = 0;
        int cnt0 = 0;
        while(r<n){
            if(nums[r]==0) cnt0++;
            if(cnt0<=k){
                maxlen = max(maxlen,r-l+1);
            }else{
                if(nums[l]==0) cnt0--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};
