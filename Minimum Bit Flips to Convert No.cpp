class Solution {
public:
    int minBitFlips(int start, int goal) {
        start = start ^ goal;
        int cnt = 0;
        for(int i =0; i<=31; i++){
            if(start & (1<<i)) cnt++;
        }
        return cnt;
    }
};
