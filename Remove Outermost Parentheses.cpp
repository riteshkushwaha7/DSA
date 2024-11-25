


class Solution {
public:
    string removeOuterParentheses(string s) {
        unordered_map<char, int> mpp;
        vector<string> temp;
        int inti = 0;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
            if (mpp['('] == mpp[')']) {
                temp.push_back(s.substr(inti, i - inti + 1));
                inti = i + 1;
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            temp[i] = temp[i].substr(1, temp[i].size() - 2);
        }

        string result = "";
        for (const auto& t : temp) {
            result += t;
        }

        return result;
    }
};
