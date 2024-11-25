

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> temp(128, {0, ' '});
        
        for (char c : s) {
            temp[c].first++;
            temp[c].second = c;
        }

        sort(temp.begin(), temp.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first; 
        });

        string result;
        for (const auto& p : temp) {
            if (p.first > 0) {
                result.append(p.first, p.second); 
            }
        }

        return result;
    }
};
