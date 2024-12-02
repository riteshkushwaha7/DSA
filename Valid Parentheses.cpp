// Valid Parentheses


class Solution {
public:
    pair<char, char> a = {'(', ')'};
    pair<char, char> b = {'{', '}'};
    pair<char, char> c = {'[', ']'};

    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == a.first || s[i] == b.first || s[i] == c.first) {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((s[i] == a.second && top == a.first) ||
                    (s[i] == b.second && top == b.first) ||
                    (s[i] == c.second && top == c.first)) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
