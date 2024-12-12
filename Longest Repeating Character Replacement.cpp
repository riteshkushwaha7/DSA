class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxFreq = 0, maxlen = 0;
        map<char, int> mpp;

        while (r < n) {
            mpp[s[r]]++;
            maxFreq = max(maxFreq, mpp[s[r]]);
            while ((r - l + 1) - maxFreq > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
