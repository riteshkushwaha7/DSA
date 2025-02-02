class Solution {
public:
    void permutation(string &digits, vector<string> &alpha, vector<string> &ans, int n, string temp) {
        if (n >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        
        int index = digits[n] - '2';
        for (char ch : alpha[index]) {
            permutation(digits, alpha, ans, n + 1, temp + ch);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> alpha = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        permutation(digits, alpha, ans, 0, "");
        return ans;
    }
};
