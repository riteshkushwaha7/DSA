// 1829. Maximum XOR for Each Query


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorVal = 0;
        int mask = (1 << maximumBit) - 1;  

        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            xorVal ^= nums[i];
        }
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int maximum = xorVal ^ mask;  
            ans.push_back(maximum);
            xorVal ^= nums.back();
            nums.pop_back();
        }
        
        return ans;
    }
};
