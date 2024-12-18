class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for (char c : t) mpp[c]++;
        int l = 0, r = 0, cnt = 0, minLen = INT_MAX, startIdx = -1;
        while (r < s.size()) {
            if (mpp[s[r]] > 0) cnt++;
            mpp[s[r]]--;
            while (cnt == t.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};
