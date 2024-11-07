// 2914. Minimum Number of Changes to Make Binary String Beautiful



class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        n/=2;
        int i = 0,cnt = 0;
        while(n){
            if(s[i]!=s[i+1]) cnt++;
            i+=2;
            n--;
        }
        return cnt;
    }
};
