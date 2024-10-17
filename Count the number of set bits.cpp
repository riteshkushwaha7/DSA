class Solution{
public:
    
    int countSetBits(int n) {
        if (n == 0) return 0;
        
        int x = log2(n); 
        int bitsUpTo2x = x * (1 << (x - 1)); 
        int msbFrom2xToN = n - (1 << x) + 1; 
        
        return bitsUpTo2x + msbFrom2xToN + countSetBits(n - (1 << x));
    }
};
