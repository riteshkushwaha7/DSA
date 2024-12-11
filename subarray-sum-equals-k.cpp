class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
          unordered_map<int, int> prefixSumFreq;
        int count = 0;
        int prefixSum = 0;
        
        prefixSumFreq[0] = 1;
        
        for (int num : nums) {
            prefixSum += num;
            if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[prefixSum - k];
            }
            prefixSumFreq[prefixSum]++;
        }
        
        return count;
    }
};
