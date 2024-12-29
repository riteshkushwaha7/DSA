template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
class Solution {
public:
    string answerString(string word, int num) {
        if (num == 1) return word;
        string ans;
        int n = word.size();
        num--;
        for (int i = 0; i < n; i++) {
            int u = num - i;
            if (n - max(0, u) <= i) continue;
            string t = word.substr(i, n - max(0, u) - i);
            if (ans.empty()) ans = t;
            else ckmax(ans, t);
        }
        return ans;
    }
};
