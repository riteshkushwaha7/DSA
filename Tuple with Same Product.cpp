class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mpp[nums[i] * nums[j]]++;
            }
        }

        int cnt = 0;
        for(auto &i : mpp){
            int freq = i.second;
            if(freq > 1){
                cnt += (freq * (freq - 1)) / 2; 
            }
        }
        return cnt * 8; 
    }
};
