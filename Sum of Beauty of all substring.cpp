




class Solution {
public:
    int beauty(string s) {
        vector<int> freq(26, 0); 
        for (char ch : s) {
            freq[ch - 'a']++; 
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {  
                maxi = max(maxi, freq[i]); 
                mini = min(mini, freq[i]); 
            }
        }

        return maxi - mini;
    }

    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += beauty(s.substr(i, j - i + 1));
            }
        }

        return ans;
    }
};
