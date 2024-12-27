class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxh = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i>maxh) return false;
            maxh = max(maxh, i + nums[i]);
        }
        return true;
    }
};
