// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence




class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int n = searchWord.size();
        int cnt = 1;
        for(int i = 0; i<s.size(); i++){
            if(i==0 || s[i-1]==' '){
                if(s.substr(i,n) == searchWord) return cnt;

                cnt++;
            }
        }
        return -1;
    }
};
