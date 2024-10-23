class Solution {
  public:
    int xorr(int r){
        if(r%4==1) return 1;
        else if(r%4==2) return r+1;
        else if(r%4==3) return 0;
        else return r;
        
    }
    int findXOR(int l, int r) {
        // complete the function here

        return xorr(l-1)^xorr(r);
    }
};
