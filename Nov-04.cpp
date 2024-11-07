// 3163. String Compression III

class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        int i = 0;
        
        while (i < n) {
            char currentChar = word[i];
            int count = 0;
            
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }
            
            comp.push_back(count + '0');
            comp.push_back(currentChar);
        }
        
        return comp;
    }
};
