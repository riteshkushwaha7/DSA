



class Solution {
public:
    void palindrome(string s, int left, int right, int& start, int& maxLength) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            int length = right - left + 1;
            if (length > maxLength) {
                maxLength = length;
                start = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLength = 0;

        for (int i = 0; i < n; i++) {
            palindrome(s, i, i, start, maxLength);
            palindrome(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }
};
