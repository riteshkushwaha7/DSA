class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        unordered_map<int, int> prefixSumMap;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < N; ++i) {
            sum += A[i];

            if (sum == K) {
                maxLen = i + 1;
            }

            if (prefixSumMap.find(sum - K) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[sum - K]);
            }

            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
