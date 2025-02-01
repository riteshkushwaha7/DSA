class Solution {
public:
    bool parity(int a, int b){
        return ((a%2==1 && b%2==0)||(a%2==0 && b%2==1));
    }
    bool isArraySpecial(vector<int>& nums) {
        bool ans = true;
        if(nums.size()==1) return true;
        for(int i = 0; i<nums.size()-1; i++){

            ans = ans && parity(nums[i],nums[i+1]);
        }
        return ans;
    }
};
