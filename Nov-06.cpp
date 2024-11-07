//3011. Find if Array Can Be Sorted

class Solution {
public:
   
    int countSetBits(int n) {
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        map<int, int> bitCountMaxValue;
        
        int pmax = 0, cmin = 0, cmax = 0;
        int pcnt = 0;

        
        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            int ccnt = countSetBits(v); 
            
            if (pcnt == ccnt) {
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = v;
                pcnt = ccnt;
            }
        }
        return cmin >= pmax;
    }
};
