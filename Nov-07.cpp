// 2275. Largest Combination With Bitwise AND Greater Than Zero


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxSize = 0;

        for (int i = 0; i < 32; ++i) {
            int count = 0;

            for (int candidate : candidates) {
                if (candidate & (1 << i)) {
                    count++;
                }
            }

            maxSize = max(maxSize, count);
        }

        return maxSize;
    }
};
