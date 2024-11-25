


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> mapST, mapTS;
        for (int i = 0; i < s.size(); i++) {
            if ((mapST.count(s[i]) && mapST[s[i]] != t[i]) || 
                (mapTS.count(t[i]) && mapTS[t[i]] != s[i])) {
                return false;
            }
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }
        return true;
    }
};
