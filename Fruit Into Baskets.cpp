class Solution {
public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size();
        int l = 0, r = 0;
        int maxf = 0;
        map<int, int> mpp; 

        while (r < n) {
            mpp[arr[r]]++;
            while (mpp.size() > 2) {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0) {
                    mpp.erase(arr[l]); 
                }
                l++; 
            }
            maxf = max(maxf, r - l + 1);
            r++; 
        }
        return maxf;
    }
};
